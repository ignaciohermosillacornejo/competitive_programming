from math import gcd
x,y,a,b = list(map(lambda x: int(x), input().rstrip('\n').split(' ')))
m = x*y//gcd(x,y)

out = b//m-a//m
if a%m == 0:
    out+=1
print(out)
