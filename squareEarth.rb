n,x1,y1,x2,y2 = gets.split(' ').map(&:to_i)
if (x1 <= y1 and x2 <= y2) or (x1 >= y1 and x2 >= y2)
  puts (x1-x2).abs + (y1-y2).abs
else
  puts [4*n-x1-x2-y1-y2, x1+x2+y1+y2].min
end
