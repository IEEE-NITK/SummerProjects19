function CollatzFunc(number)
    if (number == 1)
        println("\b\b\b: End Of Sequence")
        return        
    elseif (number % 2 == 0)
        number>>>=1
    else
        number = 3 * number + 1
    end
    print(number, " -> ")
    convert(UInt16, number)
    CollatzFunc(number)
end

println("Enter the number whose Collatz Sequence has to be printed:")
collatzNum = parse(UInt16,readline())
CollatzFunc(collatzNum)