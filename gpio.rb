GPIO_PATH = "/sys/class/gpio/"

class Port
	attr_reader :number
	attr_reader :op
	attr_reader :path
	
	def self.open(num, op, &block)
		port = Port.new(num, op)
		return port unless block_given?
		yield port
	ensure
		port.close
	end
	
	def self.close(num)
		File.write(File.join(GPIO_PATH, "unexport"), num)
		true
	rescue
		false
	end
	
	def initialize(num, op = 'r')
		dir = ''
		if op == 'r'
			dir = 'in'
		elsif op == 'w'
			dir = 'out'
		else
			raise "Unknown operation #{op}"
		end
			
		raise "Port '#{num}' already open." if File.exists? "/sys/class/gpio/gpio#{num}"
		
		@number = num
		@op = op
		@path = File.join(GPIO_PATH, "gpio#{@number}")
		
		File.write(File.join(GPIO_PATH, "export"), @number)
		IO.popen("chmod -R 777 #{@path}")
		File.write(File.join(@path, 'direction'), dir)
	end
	
	def close()
		File.write(File.join(GPIO_PATH, "unexport"), @number)
	end
	
	def puts(input)
		File.write(File.join(@path, 'value'), input)
	end
	
	def gets(input)
		File.read(File.join(@path, 'value'))
	end
end