#HammingDistance
function hammingDistance(a,b)
 c=xor(a,b)
 uno=0;
  while(c>0)
   uno+=c&1
   c=c>>>1
  end
println("Hamming Distance = $uno")
end
n1=readline()
n2=readline()
hammingDistance(parse(Int64,n1),parse(Int64,n2))