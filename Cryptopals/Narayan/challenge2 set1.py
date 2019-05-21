print("Enter the hexadecimal string:")
x=input()
y='686974207468652062756c6c277320657965'
xored=int(x, 16) ^ int(y, 16)
print('{:x}'.format(xored))
