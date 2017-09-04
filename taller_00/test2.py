s = input()
c = s[0]
d = int(s[1])

if (c == "a" or c == "h"):
    if (d == 1 or d == 8):
        print(3)
    else:
        print(5)
elif (d == 1 or d == 8):
    print(5)
else:
    print(8)
