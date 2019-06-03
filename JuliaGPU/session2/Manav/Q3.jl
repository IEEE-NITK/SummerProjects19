using BenchmarkTools
function bin_sqrt(x)
	if(x==0 || x==1)
		return x
	end
	start=1
	end1=x
	ans=0
	while(start<=end1)
		mid=(floor((start+end1)/2))
		if(mid*mid==x)
			ans=mid
			break
		end
		if(mid*mid<x)
			start=mid+1
			ans=mid
		else
			end1=mid-1
		end
	end
	inc=.1
	for i in 0:6
		while ans*ans<=x
			ans+=inc
		end
		ans-=inc
		inc/=10
	end
	return ans
end
Arr = rand(2^20)
ArrCopy = copy(Arr)
array_sqrt(Arr) = @. Arr = bin_sqrt(Arr)
@benchmark array_sqrt!(Arr)
@benchmark sqrt.(Arr)
