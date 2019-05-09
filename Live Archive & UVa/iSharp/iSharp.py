# Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2380
# Tags: Implementation
# Status: Accepted

import sys

flag = False
for line in sys.stdin:
    if (not flag):
        flag = True
    else:
        print("")

    line = line.rstrip("\n").split(" ")
    common = line[0]
    line = list(map(lambda x: x.rstrip(",").rstrip(";"), line))

    for j in range(1, len(line)):
        variable_name = ""
        count = 0
        for i in range(len(line[j])):
            if line[j][i] == '*' or line[j][i] == '&' or line[j][i] == '[':
                break
            else:
                variable_name += line[j][i]
                count += 1
        operators = line[j][count:][::-1].replace("][", "[]")
        print(common + operators + " " + variable_name + ";")
