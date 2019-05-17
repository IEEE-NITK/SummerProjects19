#Generating a mutating function and broadcasting it,followed by benchmarking against the in-built function
using BenchmarkTools
function Root(n,precision)
 start=0
 ans=0
 mid=0
 final=0
 
 while start <= final 
  mid=(start+final)/2
  
  if mid^2 == n
   ans=mid
   break
  elseif mid^2 < n
   start=mid+1
   ans=mid
  else
   final=mid-1
  end
 end
 increment=0.1
 for i in 0:precision
  while ans^2 <= n
   ans+=increment
  end
 ans=ans-increment
 increment=increment/10
 end
return ans
end
arr_sqrt!(arr) = arr.=Root.(arr,7)
A=rand(2^20)
@benchmark arr_sqrt!(A)
#=
julia> @benchmark arr_sqrt!(A)
BenchmarkTools.Trial:
  memory estimate:  16.00 MiB
  allocs estimate:  1048576
  --------------
  minimum time:     307.642 ms (0.06% GC)
  median time:      308.934 ms (0.06% GC)
  mean time:        312.883 ms (0.70% GC)
  maximum time:     340.705 ms (6.91% GC)
  --------------
  samples:          16
  evals/sample:     1
=#

@benchmark sqrt.(A)
#=
julia> @benchmark sqrt.(A)
BenchmarkTools.Trial:
  memory estimate:  8.00 MiB
  allocs estimate:  4
  --------------
  minimum time:     3.031 ms (0.00% GC)
  median time:      3.242 ms (0.00% GC)
  mean time:        3.691 ms (14.38% GC)
  maximum time:     36.720 ms (91.48% GC)
  --------------
  samples:          1354
  evals/sample:     1
+#


 
