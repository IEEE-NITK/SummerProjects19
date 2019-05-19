import codecs
print("enter the input")
x=input()
b64 = codecs.encode(codecs.decode(x, 'hex'), 'base64').decode()
print(b64)