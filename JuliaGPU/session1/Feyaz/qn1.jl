q= parse(Int32, readline())
w= parse(Int32, readline())

e= bitstring(q⊻w)
#println(e)

ans=0
for i in e
	if i=='1'
		global ans=ans+1
		#println(ans)
		end
end
println(ans)