n, m = gets.split.map(&:to_i)
deg = [0]*(n+1)
m.times do
  a, b = gets.split.map(&:to_i)
  deg[a] += 1
  deg[b] += 1
end
ans = 0
(1..n).each do |i|
  ans += deg[i]*(deg[i]-1) + (n-deg[i]-1)*(n-2*deg[i]-2)
end
puts ans/6

