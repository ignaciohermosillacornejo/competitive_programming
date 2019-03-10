i = input().split()
a=int(i[0])
b = int(i[1])
x = b-1 + (a-b+1)/2
if((a-b+1)%2 == 0):
    print(str(x))
else:
    print(x)