no=parse(UInt8,readline())
while no!=1
	if no%2==0
		global no=Int(no/2)
		println(no)
	else
		global no=Int(3*no+1)
		println(no)
	end
end
