#Square root of a no. using binary search and comparing using Test

function bs_sqrt(x)
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

using Test
a = rand(2^3)
@test sqrt.(a) ≈ bs_sqrt.(a)
isapprox(sqrt.(a),bs_sqrt.(a))
