import sys

a = int(input())
b = int(input())
c = int(input())

r1 = (a + b) + c
r2 = (a + b) * c
r3 = (a * b) * c
r4 = (a * b) + c
r5 = a + (b + c)
r6 = a + (b * c)
r7 = a * (b * c)
r8 = a * (b + c)

answers = [r1,r2,r3,r4,r5,r6,r7,r8]

print(max(answers))
