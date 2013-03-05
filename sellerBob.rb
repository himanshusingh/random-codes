dp = [0]
for i in 1..2001
	dp[i] = -1
end

n = gets.to_i

for i in 1..n
	t, x = gets.split(' ')
	x = x.to_i + 1
	if t == 'sell' && dp[x] >= 0
		dp[0] = [dp[0], dp[x] + 2**(x-1)].max
	else
		dp[x] = dp[0]
	end
end

puts dp[0]