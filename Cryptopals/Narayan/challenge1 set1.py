import binascii,base64

print("Enter the hexadecimal string:")
x=input()
x_binary=binascii.unhexlify(x)
x_base64=base64.b64encode(x_binary).decode('utf8')
print(x_base64)
