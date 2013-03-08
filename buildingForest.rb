# Problem Link: http://www.codeforces.com/problemset/problem/195/E */http://www.codeforces.com/problemset/problem/195/E
MOD = 1e9+7

class DisjointSet
	def initialize(n)
		@parent = (0..n).to_a
		@depth = [0]*(n+1)
	end

	def get(x)
		return x if @parent[x] == x
		pa = @parent[x]
		@parent[x] = get(@parent[x])
		@depth[x] += @depth[pa]
		@parent[x]
	end

	def add(root, x, w)
		@parent[root] = x
		@depth[root] = w
	end

	def depth(n)
		get(n)
		@depth[n]
	end
end


n = gets.to_i
ds = DisjointSet.new(n)
ans = 0
ar = []
n.times do |idx|
	ar = gets.split.map(&:to_i)
	(1..ar[0]).each do |i|
		v = ar[2*i -1]
		x = ar[2*i]
		root = ds.get(v)
		ans = (ans + ds.depth(v) + x)%MOD
		ds.add(root, idx+1, ds.depth(v) +x)%MOD
	end
end
puts (ans%MOD).to_i