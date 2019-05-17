#Testing the Square Root Function (Binary Search vs. In-built)
using Test 
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

@test Root(4,7) == sqrt(4)
#=
julia> @test Root(4,7) == sqrt(4)
Test Passed
=#


@test Root(3,7) == sqrt(3)
#=
julia> @test Root(3,7) == sqrt(3)
Test Failed at REPL[5]:1
  Expression: Root(3, 7) == sqrt(3)
   Evaluated: 1.732050800000001 == 1.7320508075688772
ERROR: There was an error during testing
=#
