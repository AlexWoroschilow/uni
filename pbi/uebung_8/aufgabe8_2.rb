#!/usr/bin/env ruby

class Temperature

	def initialize(temperatures = (0..100))

		@temperatures = temperatures
	end

	def print_Fahrenheit

		@temperatures.each do |temperature|

	#		puts "#{temperature}\u00B0C = #{(temperature.to_f * 9) / 5 + 32}\u00B0F"
	#	end
	
			celsius = temperature
			fahrenheit = (temperature.to_f * 9) / 5 + 32

			printf("c = %2f f = %.2f\n", celsius, fahrenheit)
		end
	end


end


d = Temperature.new
d.print_Fahrenheit