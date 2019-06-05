# -*- coding: utf-8 -*-
"""
Created on Fri May 17 19:32:23 2019
@author: Karn Tiwari
"""
#Cryptopal /Set 1 /Challenge 2
#Fixed XOR
##############################################################################
#Function for conversion of Decimal number to Binary number
def decimal_binary(n):
    n=int(n)
    m=""
    
    #Converting Decimal number to Binary number
    while (n//2)!=0:
        s=n%2
        m=m+str(s)
        n=n//2
    m=m+str(n)
    
    #Returning Binary number
    return m[::-1]
##############################################################################       
#Function for conversion of Hexadecimal number to Decimal number
def hexadecimal_decimal(n):
    n=str(n)
    
    #List containing Hex number
    z=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']

    #Dictionary containing Number and its corresponding Hex value
    y={}
    for i in range(16):
        y[i]=z[i]
        
    #Converting Hexadecimal number to Decimal number
    a=len(n)
    n=n[::-1]
    m=0
    for i in range(a):
        for j in range(16):
            if(n[i]==y[j]):
                m=m+(16**i)*j
    
    #Returning Decimal Number           
    return m

###############################################################################
#Function for conversion of Binary number to Decimal number
def binary_decimal(n):
    n=str(n)
    x=len(n)
    n=n[::-1]
    s=0
    
    #Converting Binary number to Decimal number
    for i in range(x):
       s=s+(2**i)*int(n[i])
     
    #Returning Decimal Number
    return str(s)
###############################################################################
#Function for conversion of Decimal number to Hexadecimal number
def decimal_hexadecimal(n):
    n=str(n)
    n=int(n)
    
    z=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
    y={}
    for i in range(16):
        y[i]=z[i]
        
    #Converting Decimal number to Hexadecimal number
    m=""
    while (n//16)!=0:
        s=n%16
        for i in range(16):
            if s==i:
                m=m+y[i]
        n=n//16
    for i in range(64):
        if (n%16)==i:
            m=m+y[i]
            break
   
    #Returning Hexadecimal Number      
    return m[::-1]
##############################################################################
#Taking Hexadecimal number input
n=input("Enter the Hexadecimal Number: ")
print("String1: ",n)
x=len(n)

#Hexadecimal number m
m='686974207468652062756c6c277320657965'
print("String2: ",m)
y=len(m)

#Algorithm for XOR
n=hexadecimal_decimal(n)
n=decimal_binary(n)
    
m=hexadecimal_decimal(m)
m=decimal_binary(m)
    
n=str(n)
m=str(m)
    
x=len(n)
y=len(m)
    
#XOR logic to Binary number
if x>=y:
    z=x-y
    p=""
    for i in range(z):
        p=p+"0"
    m=p+m
            
    for i in range(0,x):
        if n[i]!=m[i]:
            p=p+"1"
        else:
            p=p+"0"
        
else:
    z=y-x
    p=""
    for i in range(z):
        p=p+"0"
    n=p+n
    for i in range(0,y):
        if n[i]!=m[i]:
            p=p+"1"
        else:
            p=p+"0"
    
p=binary_decimal(p)
p=decimal_hexadecimal(p)

#Printing result of n XOR m
print("The output is String is: ",p)
