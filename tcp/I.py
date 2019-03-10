len_n = int(input())
word = input()
n = word.count('N')
p = word.count('P')
if (n >= len_n/2):
	print("NO")
elif (p > len_n/2):
	print("SI")
else:
	print("INDECISOS")
