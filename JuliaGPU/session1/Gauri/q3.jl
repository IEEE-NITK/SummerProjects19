#3. Printing ASCII values of each character in given string
function printasc(str)
        newstr = ""
#    s = firstindex(str)
    l = lastindex(str)
    for i in 1:l
        newstr*=string(Int(str[i]))
    end
#    println("$newstr")
end
str = readline()
