n=readline(stdin)
i=1
while i<=length(n)
	print(string(Int(n[i]),base=16))
	global i=i+1
end
