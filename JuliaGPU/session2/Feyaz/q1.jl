
#I tried it twice, and built in sort function was around 67+ ms, 
# and insertion sort was around 1 ms.
using BenchmarkTools
arr = rand(Int, 1048576)    #2^20=1048576
len = lastindex(arr)

#Insertion SORT!
function insort!(a)
	len=lastindex(a)
	for i in  2:len
		key=a[i]
		j = i-1
		while j>=1 && key<a[j]
			a[j+1]=a[j]
			j=j-1
		end
		a[j+1]=key
	end
end

println("Built in sort function")
println(@benchmark sort(arr))
println("Insertion sort implementation")
println(@benchmark insort(arr))
