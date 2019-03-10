import sys

def read_input(ball_stack):
  heigth = int(sys.stdin.readline().strip())

  for i in range(heigth):
    line = sys.stdin.readline().strip()
    stack_row = [int(x) for x in line.strip().split(" ")] + ["-"] * (heigth - i - 1)
    ball_stack += stack_row
  
  return heigth


ball_stack = []
heigth = read_input(ball_stack)

while(heigth > 0):
  n= heigth
  elements = n*n

  values = [0] * (n*n)
  for i in range(n):
    for j in range(n - (n - i) + 1):
      index = i * n + j
      val = 0
      k = index
      while(k >= 0 and k % n <= k // n):
        val += ball_stack[k]
        k -= n
      values[index] = val

  vector = [0] * elements
  for i in range(n):
    index = elements - 1 - i
    for j in range(n - i):
      ball_index = index - j * (n + 1)
      sol1 = sol2 = -100000 * elements
      if ball_index == elements - 1:
        max = values[ball_index]
        if max < 0:
          max = 0
        sol1 = sol2 = max
      if k % n != k // n:
        sol1 = vector[ball_index - n]
      bottom_rigth = ball_index + n + 1
      if ball_index // n == n - 1:
        bottom_rigth = ball_index + 1
      if bottom_rigth <= elements - 1:
        sol2 = values[ball_index] + vector[bottom_rigth]

      if sol1 > sol2:
        vector[ball_index] = sol1
      else:
        vector[ball_index] = sol2
  
  print(vector[elements - n])
  
  ball_stack = []
  heigth = read_input(ball_stack)
