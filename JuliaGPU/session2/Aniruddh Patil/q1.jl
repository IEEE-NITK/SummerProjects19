#Sorting Algorithm Benchmark (Random Pivot Quick Sort vs. In-built Sort)
using BenchmarkTools
function quicksort!(A,i=1,j=length(A))
    if j > i
        pivot = A[rand(i:j)]
        left, right = i, j
        while left <= right
            while A[left] < pivot
                left += 1
            end
            while A[right] > pivot
                right -= 1
            end
            if left <= right
                A[left], A[right] = A[right], A[left]
                left += 1
                right -= 1
            end
        end
        quicksort!(A,i,right)
        quicksort!(A,left,j)
    end
    return A
end
A=rand(2^20)
@benchmark sort(A) 
@benchmark quicksort!(A)
#=
julia> @benchmark sort(A)
BenchmarkTools.Trial:
  memory estimate:  8.00 MiB
  allocs estimate:  2
  --------------
  minimum time:     59.030 ms (0.00% GC)
  median time:      59.791 ms (0.00% GC)
  mean time:        60.965 ms (2.20% GC)
  maximum time:     95.645 ms (36.34% GC)
  --------------
  samples:          82
  evals/sample:     1
  
julia> @benchmark quicksort!(A)
BenchmarkTools.Trial:
  memory estimate:  0 bytes
  allocs estimate:  0
  --------------
  minimum time:     30.932 ms (0.00% GC)
  median time:      31.942 ms (0.00% GC)
  mean time:        31.976 ms (0.00% GC)
  maximum time:     33.538 ms (0.00% GC)
  --------------
  samples:          157
  evals/sample:     1

=#