print("enter the input:")
x=input()
y='686974207468652062756c6c277320657965'

print(hex(int(x,16) ^ int(y,16))[2:])