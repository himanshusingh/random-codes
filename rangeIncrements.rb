n = gets
seq = gets.split.map(&:to_i)
seq << 0
curr = 0
l = []
r = []
seq.each_with_index do |num, idx|
	while curr < num do
		l << idx+1
		curr += 1
	end
	while curr > num do
		r<< idx
		curr -= 1
	end
end

puts l.length
l.length.times do |idx|
	puts "#{l[idx]} #{r[idx]}"
end
