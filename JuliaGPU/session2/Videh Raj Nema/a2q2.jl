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


using Test

@test squareroot(16)==sqrt(16)

@test squareroot(10)==sqrt(10)

isapprox(squareroot(10),sqrt(10))