#println("ONLY ASCII PLS. NO INPUT VERIFICATION ฅ(=^･ω･^=)ฅ∫ ")

q= readline()
#println(typeof(q)):: string

ans=""
temp=""
len=lastindex(q)
for i in 1:len
	#println(string(Int32(q[i]),base=16))
	temp=string(Int32(q[i]),base=16)
	global ans= ans*temp
	end
println(ans)