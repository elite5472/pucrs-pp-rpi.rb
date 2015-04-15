load 'gpio.rb'

for i in 0...26 do
	Port.close i
end