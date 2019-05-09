positions = [int(x) for x in input().split(" ")]
l = [2,4,8,3,2,6,1,2]
s = ""
for i in positions:
	if (i == 1):
		s += "4"
	elif (i == 2):
		s += "6"
	else:
		s += str( l[ (i + 5) % 8 ] )
print(s)
