function partition(arr,start,stop)
                  pivot=arr[stop]
                  ind=start #start=1
                  for i=start:(stop-1)
                      if arr[i]<=pivot
                          arr[i],arr[ind]=arr[ind],arr[i]
                          ind=ind+1
                      end
                  end
                  arr[ind],arr[stop]=arr[stop],arr[ind]
                  #println(arr,"|",ind,"|",pivot) 
                  return ind
              end

function quicksort!(arr,start=1,stop=2^20)
                  if start<stop
                      ind=partition(arr,start,stop)
                      quicksort!(arr,start,ind-1)
                      quicksort!(arr,ind+1,stop)
                  else
                      return
              end
           #println(arr)
              end

#above 2 functions are for custom sort

arr=rand(2^20)

using Pkg
Pkg.add("BenchmarkTools")
using BenchmarkTools

#@benchmark sort(arr)  #gives result of in-built function

@time sort(arr)

@time quicksort!(arr)

#@benchmark quicksort!(arr,1,2^20)  #gives result of custom sorting function
