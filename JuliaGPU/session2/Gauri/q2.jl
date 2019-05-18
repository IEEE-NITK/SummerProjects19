#using Test

function bssqr(x)
    if x<1
        return 0
    start = 1
    stop = x
    while(start<=stop)
        mid = (start+stop)/2
        if (mid*mid)==x
            return mid
            break
        elseif (mid*mid)<x
            start = mid
        else
            stop = mid
        end
    end
end
end

println("Enter the value of x")
bssqr(x)
println("Square root of $x is $mid")
