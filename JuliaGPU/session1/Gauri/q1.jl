#1. Hamming Distance of 2 no.s
function HammingDist(s1,s2)
  res = 0
  x = xor(s1,s2)
  while(x>0)
    res = res + (x&1)
    x = x>>>1
  end
  println("Hamming Distance = $res")
end
s1=readline()
s2=readline()
HammingDist(parse(Int64,s1),parse(Int64,s2))
