load 'gpio.rb'

Port.close(17)
Port.close(18)
Port.close(15)

ports = [Port.new(17, 'w'), Port.new(18, 'w'), Port.new(15, 'w')]

while true do
	for p in ports do
		puts "#{p.number} Off"
		p.puts(0)
	end
	sleep(0.5)
	
	for p in ports do
		puts "#{p.number} On"
		p.puts(1)
	end
	sleep(0.5)
end