using Test
Array = rand(2^20)
ArrayCopy = copy(Array)

function squareroot(number)
    startNum = 0
    endNum = number
    answer = 0
    while startNum <= endNum
        middle = div((startNum + endNum),2)
        if middle*middle == number
            answer = middle 
            break
        end
        if middle*middle < number 
            startNum = middle + 1 
            answer = middle
        else
            endNum = middle - 1 
        end
    end
    
    increment = 0.1; 
    for i = 0:9 
        while answer*answer <= number 
            answer += increment
        end
        answer = answer-increment 
        increment = increment/10     
    end
    return answer
    end

array_sqrt(Array) = @. Array = squareroot(Array)

println("The time taken by the custom function and the default function, respectively:")
println(@test @time array_sqrt(Array) ≈ @time sqrt.(ArrayCopy))
