#include "ruby.h"

#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

VALUE Monotonic = Qnil;

VALUE gettime_monotonic(VALUE self) {
  struct timespec ts;

#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts.tv_sec = mts.tv_sec;
  ts.tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_REALTIME, &ts);
#endif
  return rb_float_new((double)ts.tv_sec + (double)ts.tv_nsec * 1e-9);
}

void Init_monotonic() {
  Monotonic = rb_define_module("Monotonic");
  rb_define_singleton_method(Monotonic, "now", gettime_monotonic, 0);
}

