c=readline()
n=1

while n<=length(c)
	print(string(Int(c[n]),base=16))
	global n += 1
end
print("\n")


