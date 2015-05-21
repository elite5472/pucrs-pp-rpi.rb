ARGV.each do |a|

puts "Reading #{a}...\n"
puts File.read(a)
puts "\nEOF\n"

end