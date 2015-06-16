require 'git'
require 'mail'
require 'yaml'
require 'date'

$config = YAML.load_file('config.yml')
$gitpath = File.join($config['git']['path'], $config['git']['name'])

mail_options = { 
			:address              => "smtp.gmail.com",
            :port                 => 587,
            :domain               => 'your.host.name',
            :user_name            => $config['mailing_options']['user_name'],
            :password             => $config['mailing_options']['password'],
            :authentication       => 'plain',
            :enable_starttls_auto => true  
}

Mail.defaults do
  delivery_method :smtp, mail_options
end

def notify(message, author)
	$config['mailing_list'].each do |m|
		Mail.deliver do
			to m
			from $config['mailing_options']['user_name']
			subject 'Raspberry Compile Summary'
			body "Commit Date: #{author.date}\nAuthor: #{author.name}, #{author.email}\n\n#{message}"
		end
	end
end

def check(git, last_date, command)
	puts "Pulling latest..."
	git.pull

	commit_date = git.log[0].date
	commit_timestamp = git.log[0].author.date
	commit_author = git.log[0].author.name
	commit_email = git.log[0].author.email
	
	if(commit_date > last_date)
		puts "Last commit by #{commit_email} at #{commit_timestamp}."
		puts "Running #{command}..."
		
		output = ""
		exit_code = 0
		Dir.chdir($gitpath) do
			output = `#{command} 2>&1`
			exit_code = $?.exitstatus
		end
		
		message = "Project successfully compiled.\n\n#{output}"
		
		if exit_code > 0 
			message = "Exit code #{exit_code}.\n\n#{output}"
			`./led_controller 1`
		else
			`./led_controller 0`
		end
		
		notify(message, git.log[0].author)
	end
	
	commit_date
end

last_commit = Time.new(1980, 1, 1)
git = nil

puts $config['git']['url']
puts $config['git']['name']
puts $config['git']['path']

begin
	git = Git.clone($config['git']['url'], $config['git']['name'], :path => $config['git']['path'])
rescue
	git = Git.init($gitpath)
end

while true do
	last_commit = check(git, last_commit, $config['git']['run'])
	sleep(10)
end
