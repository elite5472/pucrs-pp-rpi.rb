load 'gpio.rb'

for i in [1, 15, 17, 18] do
	Port.close(i)
end

$leds = [Port.new(15,'w'), Port.new(17,'w'), Port.new(18,'w')]
$button = Port.new(1,'r')

def set_led(color)
	case color
	when 'green'
		$leds[0].puts(1)
		$leds[1].puts(0)
		$leds[2].puts(0)
	when 'yellow'
		$leds[0].puts(0)
		$leds[1].puts(1)
		$leds[2].puts(0)
	when 'red'
		$leds[0].puts(0)
		$leds[1].puts(0)
		$leds[2].puts(1)
	else
		raise "Unknown color #{color}."
	end
end

while true do
	set_led('green')
	sleep(10.0)
	set_led('yellow')
	sleep(2.0)
	set_led('red')
	sleep(8.0)
end