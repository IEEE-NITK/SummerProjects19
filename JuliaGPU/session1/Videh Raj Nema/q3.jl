str=readline()
final=""
for each in str
    global final
    final=final*string(Int(each),base=16)
end
println(final) #prints the final string
