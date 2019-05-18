#Mutating function array_sqrt and it's comparison with julia's sqrt() function

#a = rand(2^20)
using Pkg

array_sqrt!(a) = a ^(1/2)
#println(array_sqrt(a))
a = rand(2^20)
println("Benchmark:")
println("Default sqrt function in Julia: ")
@time begin
  sqrt.(a)
end
println("Custom square root function written by me: ")
@time begin
  array_sqrt.(a)
end
