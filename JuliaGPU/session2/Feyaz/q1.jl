using BenchmarkTools
arr = rand(Int, 1048576)    #2^20=1048576
len = lastindex(arr)

function quicksort!(array,low=1,high=length(array))
    k=trunc(Int64, (high+low)/2)
    if high > low
        pivot = array[k]
        left, right = low, high
        while left <= right
            while array[left] < pivot
                left += 1
            end
            while array[right] > pivot
                right -= 1
            end
            if left <= right
                array[left], array[right] = array[right], array[left]
                left += 1
                right -= 1
            end
        end
        quicksort!(array,low,right)
        quicksort!(array,left,high)
    end
    return array
end

println("Built in sort function")
println(@benchmark sort(arr))
println("Quicksort implementation")
println(@benchmark quicksort!(arr))
