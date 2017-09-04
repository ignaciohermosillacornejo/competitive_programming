n_moves = 0

n = int(input())
soldiers = list(map(lambda x: int(x), input().split()))
length = len(soldiers)
s_min = min(soldiers)
s_max = max(soldiers)
i_max = soldiers.index(s_max) # retorna el primer caso
soldiers = soldiers[::-1]
i_min = length - soldiers.index(s_min) - 1  # retorna el ultimo caso


n_moves += (length - (i_min + 1))
#print(n_moves)
n_moves += i_max
#print(n_moves)
#print("i min")
#print(i_min)
#print("i max")
#print(i_max)

if (i_min < i_max): # en caso de que se tengan que cruzar los numeros restamos 1 numero
    n_moves -= 1
print(n_moves)
