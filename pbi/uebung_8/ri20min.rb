#!/usr/bin/env ruby

class MegaGreeter
	attr_accessor :names 							# Create the object

	def initialize(names = "World")
		@names = names
	end

	def say_hi 										# Say hi to everybody
		if @names.nil?
			puts "..."
		elsif @names.respond_to?("each") 			# @names is a list of some kind, iterate!
			@names.each do |name|
			puts "Hello #{name}!"
			end
		else
			puts "Hello #{@names}!"
		end
	end

	def say_bye # Say bye to everybody
		if @names.nil?
			puts "..."
		elsif @names.respond_to?("join") 			# Join the list elements with commas
			puts "Goodbye #{@names.join(", ")}. Come back soon!"
		else
			puts "Goodbye #{@names}. Come back soon!"
		end
	end
end

puts "__FILE__=#{__FILE__}" # name of this file
puts "$0=#{$0}" # name of running ruby script
if __FILE__ == $0
  namelist = ["Albert", "Brenda", "Charles", "Dave", "Joe"]
  mg = MegaGreeter.new
  mg.say_hi
  mg.say_bye
  mg.names = "John" 								# Change name to be "John"
  mg.say_hi
  mg.say_bye										# Change the name to an array of names
  puts namelist.join("; ")
  mg.names = namelist
  mg.say_hi
  mg.say_bye
  mg.names = nil 									# Change to nil
  mg.say_hi
  mg.say_bye
end