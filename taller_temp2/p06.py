import copy


LIS = []

def find_lis(lst):


    # LIS = [ [[1]], [[1, 3]], [[1, 2]], [[1, 3, 5], [1, 2, 5]] ]
    LIS.append([[0]])
    for i in range(1, len(lst)):
        # print(i)
        LIS.append([[]])
        for j in range(0, i):
            # print("i: {} j: {}".format(i, j))
            if (lst[j] < lst[i]):
                if (len(LIS[j][0]) > len(LIS[i][0])):
                    LIS[i] = copy.deepcopy(LIS[j])
                elif (len(LIS[j][0]) == len(LIS[i][0])):
                    for item in LIS[j]:
                        LIS[i].append(copy.deepcopy(item))
        for item in LIS[i]:
            item.append(i)

    
n = input()
n = int(n)
cnt = [0] * n
lst = [int(x) for x in input().split()]
find_lis(lst)


highest = -1
for item in LIS:
    highest = max(highest, len(item[0]))

n_lis = 0
for i in range(0, len(LIS)):
    if (len(LIS[i][0]) == highest):
        for item in LIS[i]:
            n_lis += 1
            for number in item:
                cnt[number] += 1
answer = ""
for number in cnt:
    if number == n_lis:
        answer += "3"
    elif number == 0:
        answer += "1"
    else:
        answer += "2" 
print(answer)
