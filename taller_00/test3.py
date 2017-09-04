from collections import Counter

k = int(input())
s_string = input()

length = len(s_string)
lets=Counter(s_string)

if (k == 1):
    print(s_string)
    exit()

if (k == length):
    if (len(lets) == 1):
        print(s_string)
        exit()
    else:
        print(-1)
        exit()

if (length % k != 0):
    print(-1)
    exit()

l = int((length)/k)



#print(lets)


for x in lets:
    if (lets[x] % k != 0):
        print(-1)
        exit()

# Existe solucion la construimos
p_answer = ""
for x in lets:
    i = int(lets[x] / k)
    for j in range(i):
        p_answer += x

answer = ""
for x in range(k):
    answer += p_answer
print(answer)
