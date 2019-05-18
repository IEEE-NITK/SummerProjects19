using Test
#=   =#
function bs_sqrt(x)
    if x<1
        return 0
    start = 1
    stop = x
    while(start<=stop)
        mid = (start+stop)//2
        if (mid*mid)==x
            ans = mid
            return ans
            break
        elseif (mid*mid)<x
            start = mid+1
            ans = mid
        else
            stop = mid-1
        end
    end
end
end
@test bs_sqrt(x)
@test sqrt(x)
