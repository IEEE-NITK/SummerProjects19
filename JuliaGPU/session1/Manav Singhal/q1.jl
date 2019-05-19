function dectobin(no)
	coun=0
	no1=0
	while no!=0
		remai=no%2
		no1=no1+remai*(10^coun)
		coun=coun+1
		no=Int(floor(no/2))
	end
	return no1
end
number1=parse(UInt8, readline())
number2=parse(UInt8, readline())
ans=xor(number1,number2)
c=0
ans=dectobin(ans)
while ans!=0
	global remain=ans % 10
	if remain==1
		global c=c+1
	end
	global ans= Int(floor(ans/10))
end
println("Hamming Distance: ",c)
	
