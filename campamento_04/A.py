from math import ceil

def gcd(n, m):
    r0 = n
    r1 = m
    s1 = t0 = 0
    s0 = t1 = 1
    while r1 != 0:
        q = r0//r1
        r = r0 - q*r1
        r0 = r1
        r1 = r
        s = s0 - q*s1
        s0 = s1
        s1 = s
        t = t0 - q*t1
        t0 = t1
        t1 = t
    return [r0,s0,t0]

while True:
    S = input().split(" ")
    x = int(S[0])
    y = int(S[1])
    z = int(S[2])
    if x == y == z == 0:
        break
    if x == y == 0:
        print("Unquibable!")
        continue
    g,a,b = gcd(x,y)
    if z % g != 0:
        print("Unquibable!")
        continue
    y//=g
    x//=g
    z//=g
    #n = ceil(-a*z/y)
    if a*z % y == 0:
        n = -a*z//y
    else:
        n = (-a*z)//y + 1
    if b*z - n*x < 0:
        print("Unquibable!")
    else:
        A = a*z + n*y
        B = b*z - n*x
        s1 = "foom"
        s2 = "foob"
        if A != 1:
            s1 +="s"
        if B != 1:
            s2 +="s"
        print(A,s1,"and",B,s2,"for a twob!")

