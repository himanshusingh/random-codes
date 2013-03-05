n = gets.to_i
pile = gets.split.map(&:to_i)
q = gets.to_i
k = gets.split.map(&:to_i)
x = Array.new(pile.size+1, 0)
pile.sort!
pile.each_with_index { |v, i| x[i+1] = x[i] + v }

k.each do |v|
	idx = pile.size-1; e = 1;
	ans = 0
	while idx != 0
		ans = ans + x[idx]
		e = [e*v,idx].min
		idx = idx - e
	end
	puts ans
end
