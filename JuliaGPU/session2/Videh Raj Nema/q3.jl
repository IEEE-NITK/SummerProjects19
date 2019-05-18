function squareroot(num)
           start=0
           stop=num
           ans=0
           while start <= stop
               mid=div((start + stop),2)
               if mid*mid==num
                   ans=mid 
                   break
               end
               if mid*mid<num 
                   start = mid + 1 
                   ans = mid
               else
                   stop = mid - 1 
               end
           end
           
           inc=0.1; 
           for i=0:9 
               while ans*ans<=num 
                   ans+=inc
               end
               ans=ans-inc 
               inc=inc/10     
           end
           return ans
           end

a=rand(2^20)
b=rand(2^20)


array_sqrt!(a)= return squareroot.(a)

a=array_sqrt!(a)


builtin!(b)=return sqrt.(b)      

b=builtin!(b)

@time builtin!(b)

@time array_sqrt!(a)
