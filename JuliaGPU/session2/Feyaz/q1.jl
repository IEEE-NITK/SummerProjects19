
#I tried it twice, and built in sort function was around 67+ ms, 
# and insertion sort was around 1 ms.
using BenchmarkTools
arr = rand(Int, 1048576)    #2^20=1048576
len = lastindex(arr)

function quicksort!(array)
    if length(array) > 1
        left=firstindex(array)
        right=lastindex(array)

        pivot= array[trunc(Int64,(left+right)/2)]
        while left ≤ right
            while array[left] < pivot
                left= left + 1
            end
            while array[right] > pivot
                right= right - 1
            end
            if left ≤ right
                array[left], array[right]=array[right], array[left]
                left= left + 1
                right= right - 1
            end
        end
        l=firstindex(array)
        h=lastindex(array)
        quicksort!(array[l:right])
        quicksort!(array[left:h])
    else
        return(array)
    end
end

println("Built in sort function")
println(@benchmark sort(arr))
println("Quicksort implementation")
println(@benchmark quicksort!(arr))
