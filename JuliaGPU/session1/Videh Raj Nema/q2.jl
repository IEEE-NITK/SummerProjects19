n=parse(Int64,readline())
while n!=1
    if n%2==0
        n=div(n,2)
    else
        n=3n+1
    end
    println(n)
end
