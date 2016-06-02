randomValue = rand(10)
#puts "#{randomValue}"
begin
puts "Guess a number"
#input = gets()
#guess = Integer(input)
guess = gets()
#puts "actual value is ]#{randomValue}[ and you guessed ]#{guess.to_i}["
puts 'za malo' if guess.to_i <  randomValue
puts 'za duzo' if guess.to_i >  randomValue
end while !(guess.to_i == randomValue)
puts "you guessed"
