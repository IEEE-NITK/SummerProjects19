#Collatz Sequence
function collatzSequence(a)
 while a != 1
  println("$a")
  if a%2 == 0
   a=trunc(Int64,a/2)
  else
   a=(3*a)+1
  end
 end
 println("$a")
end
x=readline()
collatzSequence(parse(Int64,x))