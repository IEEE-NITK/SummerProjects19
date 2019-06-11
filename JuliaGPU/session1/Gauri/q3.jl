#3. Printing ASCII values of each character in given string
function printasc(str)
        newstr = ""
    s = firstindex(str)
    l = lastindex(str)
    for i = s:l
        newstr=string(newstr*string(convert(Int,str[i])),base = 16)
    end
   println("$newstr")
end
println("Enter string")
str = readline()
printasc(str)
