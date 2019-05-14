n = parse(UInt8,readline())
while n!=1
	print(convert(UInt8,n))
	print(" -> ")
	if n%2==0
		global n = n/ 2
	else
		global n = 3*n + 1
	end
end
print("1\n")
