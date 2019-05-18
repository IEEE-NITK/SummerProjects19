#Collatz
q=parse(Int64, readline())
#println(q)

while q!=1
	print(convert(Int64,q))
	print("->")
	if (q%2)==0
		global q=q/2
	else
		global q = 3*q+1
	end
end
print("1\n")