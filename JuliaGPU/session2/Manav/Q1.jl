function Quicksort!(arr,low,high)
	function Partition!(arr,low,high)
   		i=low-1
  		pivot=arr[high]
    		for j =low:(high-1)
        		if arr[j]<=pivot
            			i=i+1
            			arr[i],arr[j]=arr[j],arr[i]
			end
		end
        	arr[i+1],arr[high]=arr[high],arr[i+1]
    		return(i+1)
	end
	if low<high
		pivot=Partition!(arr,low,high)
    		Quicksort!(arr,low,pivot)
    		Quicksort!(arr,pivot+1,high)
	end
	println(arr)
end
arr=rand(2^2)
arr1=copy(arr)
arr2=copy(arr)
print("Default sort Algo: ")
@time sort!(arr2)
print("Quicksort Algo: ")
Quicksort!(arr1,1,length(arr1))
@time Quicksort!(arr1,1,length(arr1))
