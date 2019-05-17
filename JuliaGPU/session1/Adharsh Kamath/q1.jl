function hammingDist(num1, num2)
    tempString = (num1 ⊻ num2)
    NoOfDiffBits = 0
    while tempString > 0
        NoOfDiffBits += (tempString & 1)
        tempString>>>=1        
    end
    println("The Hamming distance between " , num1 , " and " , num2 , " is " , NoOfDiffBits)
end

println("Enter the two integers:")
number1 = parse(UInt16, readline())  
number2 = parse(UInt16, readline())
hammingDist(number1, number2)      