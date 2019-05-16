n = parse(UInt8, readline())
if n>0
  println(n)
  while(n!=1)
    if n%2==0
       global n = n/2
       println(n)
    else
       global n = (3*n)+1
       println(n)
    end
  end
end
