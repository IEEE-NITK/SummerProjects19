#Sorting a random array of 2^20 elements using quicksort and comparing it with julia builtin sort using @time

#a = rand(2^3)
#println("Random array a before sorting: $a")
#println("a after sorting:")
function partition(a,p,r)
  x = a[r]
  i = p-1
  for j = p:r
    if a[j]<=x
      i=i+1
      a[i],a[j] = a[j],a[i]
    end
  end
  a[i+1],a[r] = a[r],a[i+1]
  return i+1
end

function sortfunc!(a, p = 1, r = 2^20)
  if low<high
    q = partition(a,p,r)
    sortfunc(a,p,q-1)
    sortfunc(a,q+1,r)
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
println("Custom quick sort function written by me: ")
@time begin
  sortfunc(a)
end
