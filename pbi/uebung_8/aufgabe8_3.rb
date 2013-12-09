#!/usr/bin/env ruby

dna = "ACGAATT  ACTTTAGC"
rna = dna.gsub(/T/, "U")
print "\n\tHere is the starting DNA:  "
print "#{dna}\n"
print "\tHere is the result:  "
puts "#{rna}\n\n"
exit 0