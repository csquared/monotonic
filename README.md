# Monotonic

Provides a wrapper for C Ruby on OS X and Linux machines for monotonic system calls.

This gem is useful for machines that are set to network time and are constantly shifting
their clock due to NTP.

## Installation

Add this line to your application's Gemfile:

    gem 'monotonic'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install monotonic

## Usage

```ruby
require 'monotonic'

now = Monotonic.now
# => 3053.775931588
 elapsed = Monotonic.now - now
# => 9.032509741000013
```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
