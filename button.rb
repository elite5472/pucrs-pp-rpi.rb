#Define Project Path
$LOAD_PATH.unshift File.dirname(__FILE__)
###

require 'gpio.rb'

Port.close(14)
Port.close(22)

Port.open(14, 'w') do |p14|
	Port.open(22, 'r') do |p22|
		while true do
			if p22.gets == '0'
				p14.puts(0)
			else
				p14.puts(1)
			end
		end
	end
end