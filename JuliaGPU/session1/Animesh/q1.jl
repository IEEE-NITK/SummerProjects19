m = parse(UInt8, readline())
n = parse(UInt8, readline())
c = xor(m,n)
count = 0
while c!=0
  c = c & (c-1)
  count = count+1
end
println(count)                 
