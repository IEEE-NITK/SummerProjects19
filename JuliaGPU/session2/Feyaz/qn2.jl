using Test

#rootinator func takes the roots.

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
	prec=15#for Int64, ig
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
q=0
println("INTERACTIVE ლ(=^･ω･^=)ლ")
while(true)
	println("pick a number, within reasonable limits.")
	print(">>")
	global q=parse(Int64,readline())
	if q>0
		break
	end
end

k=rootinator(q)
l=sqrt(q)
var=isapprox(k,l)
if var
	println("Test passed! Custom fn has comparable accuracy")
	println("sqrt=> $l,        rootinator=>$k")
else
	println("Test failed?! Nani?!")
end