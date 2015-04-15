#Define Project Path
$LOAD_PATH.unshift File.dirname(__FILE__)
###

load 'gpio.rb'
#require 'gpio.rb'


Port.open(14, 'w') do |p14|
	p14.puts('1')
end