using Test
function bin_sqrt(x)
        if(x==0 || x==1)
                return x
        end
        start=0
        end1=x
	ans=0
        while start<=end1 
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
        for i = 0:6
                while ans*ans<=x
                        ans+=inc
                end
                ans-=inc
                inc/=10
        end
        return ans
	end
println("Enter no: ")
no=parse(Float64,readline())
println("Sqrt custom: ",bin_sqrt(no))
println("Sqrt default: ",sqrt(no))
println(@test bin_sqrt(no)≈sqrt(no))
