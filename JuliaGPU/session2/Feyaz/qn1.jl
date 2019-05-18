#Try using arr as the 10 digit array, if you're impatient.
#I tried it twice, and built in sort function was around 67+ ms, 
# and insertion sort was around 1 ms. I'll put a picture, too.
using BenchmarkTools
arr = rand(Int, 1048576)    #2^20=1048576
#arr = [9,7,8,4,5,3,6,2,1,0]
len = lastindex(arr)

#Insertion SORT!
function insort(a)
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
#println("The array:")
#for x in arr
#	println(x)
#end

println("Built in sort function")
println(@benchmark sort(arr))
println("Insertion sort implementation")
println(@benchmark insort(arr))
