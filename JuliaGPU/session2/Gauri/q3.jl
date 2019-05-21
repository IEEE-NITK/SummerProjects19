#Mutating function array_sqrt and it's comparison with julia's sqrt() function

function array_sqrt!(x)
    start=0
    stop=x
    ans=0
    while start <= stop
        mid=(start + stop)/2
        if mid*mid==x
            ans=mid
            break
        end
        if mid*mid<x
            start = mid + 1
            ans = mid
        else
            stop = mid - 1
        end
    end
    inc=0.1;
    for i=0:9
        while ans*ans<=x
            ans+=inc
        end
        ans=ans-inc
        inc=inc/10
    end
    return ans
end
#println(array_sqrt(a))
a = rand(2^20)
println("Benchmark:")
println("Default sqrt function in Julia: ")
@time begin
  sqrt.(a)
end
println("Custom square root function written by me: ")
@time begin
  array_sqrt!.(a)
end
