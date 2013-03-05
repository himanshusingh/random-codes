def raise(y, n, mod)
	res = 1
	x = y
	while n != 0
		res = (res*x)%mod if n%2 != 0
		x = (x*x)%mod
		n = n/2
	end
	res
end
n, mod = gets.split.map(&:to_i)
ans = (raise(3, n, mod) - 1)%mod
puts ans
