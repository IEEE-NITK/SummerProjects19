x=parse(Int64,readline())
y=parse(Int64,readline())

result=xor(x,y)
arr=[]

while result!=1
        global result
        push!(arr,(result%2))
        result=div(result,2)
end
push!(arr,1)

count=0

for i in arr
    if i==1
            global count
            count+=1
    end
end

println(count)
