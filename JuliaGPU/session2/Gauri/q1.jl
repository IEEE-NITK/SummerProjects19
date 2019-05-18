#Sorting a random array of 2^20 elements using bubble sort and

#a = rand(2^3)
#println("Random array a before sorting: $a")
#println("a after sorting:")
function sortfunc(a)
  for i in 1:(2^3)
    for j in (i+1):(2^3)
      if a[j]<a[i]
        temp = a[i]
        a[i] = a[j]
        a[j] = temp
      end
    end
  end
end

a = rand(2^20)
#println("Random array a before sorting: $a")
#println("a after sorting:")
println("Benchmark:")
println("Default sort function in julia: ")
@time begin
  sort(a)
end
#println(b)
println("Custom bubble sort function written by me: ")
@time begin
  sortfunc(a)
end
