# -*- coding: utf-8 -*-
"""
Created on Fri May 24 19:30:39 2019
@author: Karn Tiwari
"""
#Calculating XOR'd
def single_char_xor(input_bytes,char_value):
    output_bytes=b''
    for byte in input_bytes:
        output_bytes+=bytes([byte^char_value])
    return output_bytes
    
#Calculating Score
def score(decodemessage):
    decodemessage=decodemessage.lower()
    character_frequencies = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
        'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
        'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
        'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
        'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
        'y': .01974, 'z': .00074, ' ': .13000
    }
    
    x=0
    
    for i in decodemessage:
        if i in character_frequencies:
            x+=character_frequencies[i]
            
    return(x)

#Reading a File and Decoding each line
ciphers=open('c.txt').read().splitlines()
max=0
p=""
for hexstring in ciphers:
    ciphertext=bytes.fromhex(hexstring)
    for i in range(1,256):
        message=single_char_xor(ciphertext,i)
        y=message.hex()
        z=''.join([chr(int(''.join(c),16)) for c in zip(y[0::2],y[1::2])])
        s=score(z)
        if s>max:
            max=s
            p=z
            k=i
            
#Printing the Result          
print("Message: ",p)
print("Key: ",i)
print("Score: ",max)
