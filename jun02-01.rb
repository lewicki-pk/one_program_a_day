# print Array of 16 elements by 4 slices
someArray = Array.new(16) { |e| e = e }
puts "#{someArray}"
puts "petla po cztery\n\n"
for x in 0..3
    y = x * 4
    puts "#{someArray[y..y+3]}"
end
puts "\nkoniec petli\n\n"
puts "teraz uzywajac each_slice\n\n"
someArray.each_slice(4) { |a| p a } # I don't understand { |a| p a } part but it works

# print Enumberable with "each_slice"
#class SomeClass
#    include Enumberable
#
#    def each
#        yield "red"
#        yield "green"
#        yield "blue"
#    end
#end
#
#c = SomeClass.new

