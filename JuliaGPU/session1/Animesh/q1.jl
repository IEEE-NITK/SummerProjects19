m = parse(UInt8, readline())
n = parse(UInt8, readline())
c = xor(m,n)
count = 0
while c!=0
  global c = c & (c-1)
  global count = count+1
end
println(count)                 
