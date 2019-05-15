#2. Collatz Sequence of a no.
function CollatzSequence(N)
    while N!=1
        println("$N->")
        if N%2==0
            N = trunc(Int64,N/2)
        else
            N = (3*N) + 1

        end
    end
end
N=readline()
CollatzSequence(parse(Int64,N))
