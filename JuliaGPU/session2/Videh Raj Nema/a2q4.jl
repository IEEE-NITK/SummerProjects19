A=[[2,1];[4,3];[6,5]]
#=6-element Array{Int64,1}:
 2
 1
 4
 3
 6
 5
=#

B=[[2,1],[4,3],[6,5]]
#=3-element Array{Array{Int64,1},1}:
 [2, 1]
 [4, 3]
 [6, 5]
=#
sqrt.(A)
#=6-element Array{Float64,1}:
 1.4142135623730951
 1.0               
 2.0               
 1.7320508075688772
 2.449489742783178 
 2.23606797749979  
=#
sort.(A)
#=ERROR: MethodError: no method matching sort(::Int64)
Closest candidates are:
  sort(::AbstractUnitRange) at range.jl:936
  sort(::AbstractRange) at range.jl:939
  sort(::SparseArrays.SparseVector{Tv,Ti}; kws...) where {Tv, Ti} at /buildworker/worker/package_linux64/build/usr/share/julia/stdlib/v1.0/SparseArrays/src/sparsevector.jl:1859
  ...
Stacktrace:
 [1] _broadcast_getindex_evalf at ./broadcast.jl:582 [inlined]
 [2] _broadcast_getindex at ./broadcast.jl:555 [inlined]
 [3] getindex at ./broadcast.jl:515 [inlined]
 [4] copy at ./broadcast.jl:790 [inlined]
 [5] materialize(::Base.Broadcast.Broadcasted{Base.Broadcast.DefaultArrayStyle{1},Nothing,typeof(sort),Tuple{Array{Int64,1}}}) at ./broadcast.jl:756
 [6] top-level scope at none:0
=#
sqrt.(B)
#=ERROR: MethodError: no method matching sqrt(::Array{Int64,1})
Closest candidates are:
  sqrt(::Float16) at math.jl:1018
  sqrt(::Complex{Float16}) at math.jl:1019
  sqrt(::Missing) at math.jl:1070
  ...
Stacktrace:
 [1] _broadcast_getindex_evalf at ./broadcast.jl:582 [inlined]
 [2] _broadcast_getindex at ./broadcast.jl:555 [inlined]
 [3] getindex at ./broadcast.jl:515 [inlined]
 [4] copy at ./broadcast.jl:790 [inlined]
 [5] materialize(::Base.Broadcast.Broadcasted{Base.Broadcast.DefaultArrayStyle{1},Nothing,typeof(sqrt),Tuple{Array{Array{Int64,1},1}}}) at ./broadcast.jl:756
 [6] top-level scope at none:0
=#
sort.(B)
#=3-element Array{Array{Int64,1},1}:
 [1, 2]
 [3, 4]
 [5, 6]
=#



#=

sqrt.(A)-> works as it is an example of broacasting. A is a 6 element integer array and doing sqrt.(A) applies the square root operation on each element of array (but does not muatates the array).

sort.(A)-> each element of A is an integer. Since here broadcasting is applied, sort() function acts upn each integer in A. Doing something like say sort(2) will produce an error.

sqrt.(B)-> B is an 2d array with 3 rows and 2 columns. sqrt.(B) tries to apply the square root operation to each element of array B. But each element of B is itself an array of 2 elements. Broadcasting is required for those 2 elements also. Hence it shows error.

sort.(B)-> each element of B is itself an array. sort.(B) does broadcasting and applies sorting operation to each element of B, which is an array. Hence that particular array gets sorted (but not mutated).


=#