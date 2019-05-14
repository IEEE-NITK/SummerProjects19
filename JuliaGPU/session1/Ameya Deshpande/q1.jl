m = parse(UInt8, readline())
n = parse(UInt8, readline())
x = m⊻n
#println(x)
c=0
while x!=0
	p=0
	while (2^p)<=x
		#println(p)
		p += 1
	end
	#println(p)
	global x -= (2^(p-1))
	global c += 1
end
println(c)	
