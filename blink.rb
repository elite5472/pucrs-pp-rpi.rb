load 'gpio.rb'

Port.close(17)
Port.close(18)
Port.close(19)

ports = [Port.open(17, 'w'), Port.open(18, 'w'), Port.open(15, 'w')]

while true do
	for p in ports do
		p.puts(0)
	end
	sleep(0.5)
	
	for p in ports do
		p.puts(1)
	end
	sleep(0.5)
end