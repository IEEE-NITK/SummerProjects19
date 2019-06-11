"""
Spyder Editor

@Author - Karn Tiwari
"""
#Cryptopal /Set 1 /Challenge 1
#Convert Hexadecimal number to base64 number
#Taking Hexdecimal number as input
x=input("Enter the Hexadecimal Number: ")

#List containing Hexadecimal number
z=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']

#Dictionary containing Number and its corresponding Hexadecimal value
y={}
for i in range(16):
    y[i]=z[i]

#List containing Base64 number
w=[0 for i in range(64)]
for i in range(64):
    if i<26:
        w[i]=chr(65+i)
    elif i==26 or i<52:
        w[i]=chr(97+i-26)
    elif i==52 or i<62:
        w[i]=chr(48+i-52)
    elif i==62:
        w[i]='+'
    else:
        w[i]='/'

#Dictionary containing Number and its corresponding Hexadecimal value
u={}
for i in range(64):
    u[i]=w[i]

#Converting Hexadecimal number to Decimal number
a=len(x)
x=x[::-1]
n=0
for i in range(a):
    for j in range(16):
        if(x[i]==y[j]):
            n=n+(16**i)*j

#Converting Decimal number to Base64 number
m=""
while (n//64)!=0:
    s=n%64
    for i in range(64):
        if s==i:
            m=m+u[i]
    n=n//64
for i in range(64):
        if (n%64)==i:
            m=m+u[i]
            break

#Printing Base64 number
print("The Number in Base 64:", m[::-1])
