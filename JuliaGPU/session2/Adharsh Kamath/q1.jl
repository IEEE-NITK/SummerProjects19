function quicksort!(A,i=1,j=length(A))  #quick-sort algorithm
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

RandomArray = rand(2^20)
A = RandomArray
B = RandomArray
 print("Custom sort algorithm: ")
 @time quicksort!(A)
 print("Default sort algorithm: ")
 @time sort!(B)