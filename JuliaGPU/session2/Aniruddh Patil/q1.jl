#Sorting Algorithm Benchmark (Random Pivot Quick Sort vs. In-built Sort)
using BenchmarkTools
function quicksort(A,i=1,j=length(A))
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
        quicksort(A,i,right)
        quicksort(A,left,j)
    end
    return A
end
A=rand(2^20)
@benchmark quicksort(A)
@benchmark sort(A) 
#=
julia> @benchmark quicksort(A)
BenchmarkTools.Trial:
  memory estimate:  0 bytes
  allocs estimate:  0
  --------------
  minimum time:     30.513 ms (0.00% GC)
  median time:      31.240 ms (0.00% GC)
  mean time:        31.273 ms (0.00% GC)
  maximum time:     33.082 ms (0.00% GC)
  --------------
  samples:          160
  evals/sample:     1
  
julia> @benchmark sort(A)
BenchmarkTools.Trial:
  memory estimate:  8.00 MiB
  allocs estimate:  2
  --------------
  minimum time:     11.411 ms (0.00% GC)
  median time:      11.786 ms (0.00% GC)
  mean time:        12.548 ms (6.88% GC)
  maximum time:     49.536 ms (76.16% GC)
  --------------
  samples:          399
  evals/sample:     1

=#