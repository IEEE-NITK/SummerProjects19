#qn3
using BenchmarkTools

function rootinator(num)
	start=0
	fin=num
	ans=0
	#step=0
	while start<=fin
		mid= trunc(Int, (start+fin)/2)
		if(mid*mid==num)
			ans=mid
			break
		end
		if (mid*mid<num)
			start=mid+1
			ans=mid
		else
			fin=mid-1
		end
		#println(step)
		#step=step+1
	end
	inc=0.1
	prec=15			#for Int64, ig
	#step=0
	for i in 1:prec
		while(ans*ans<=num)
			ans=ans+inc
		end
		ans=ans-inc
		inc=inc/10
		#println(step)
		#step=step+1
	end
	return(ans)
end
println("Using custom sqrt fn")
array_sqrt(arr)=rootinator.(arr)

#funcroot(arr)= begin
#				len=lastindex(arr)
#				println("Using built in root fn")
#				for i in 1:len
#					arr[i]=sqrt(arr[i])
#					#println(arr[i])
#				end
#			end

a = rand(Float64, 1048576) 
b = rand(Float64, 1048576) 
#a=[1.0,2,3,4,5,6,7,8,9] #We need 1.0 there so it stores as float array.
#b=[1.0,2,3,4,5,6,7,8,9]
k=@time array_sqrt(a)
println("Using built in non mutating sqrt")
l=@time sqrt.(b)
