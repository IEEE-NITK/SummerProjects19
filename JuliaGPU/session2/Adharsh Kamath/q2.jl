using Test

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
    for i = 0:7
        while answer*answer <= number 
            answer += increment
        end
        answer = answer-increment 
        increment = increment/10     
    end
    return answer
    end
println("Enter the number whose squareroot has to be evaluated:")
number = parse(Float64,readline())
println("The squareroot using binary search is ",squareroot(number))
println("The squareroot using default sqrt function is ",sqrt(number))
println(@test squareroot(number) ≈ sqrt(number))
