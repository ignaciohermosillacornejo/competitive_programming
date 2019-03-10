h = input()


rank = 25
streak = 0
stars = 0


rank_points = {
    1: 5,
    2: 5,
    3: 5,
    4: 5,
    5: 5,
    6: 5,
    7: 5,
    8: 5,
    9: 5,
    10: 5,
    11: 4,
    12: 4,
    13: 4,
    14: 4,
    15: 4,
    16: 3,
    17: 3,
    18: 3,
    19: 3,
    20: 3,
    21: 2,
    22: 2,
    23: 2,
    24: 2,
    25: 2
}


for match in h:

    if (match == "W"):
        streak += 1
        stars += 1
        if (streak >= 3 and rank >= 6):
            stars += 1

    else:
        streak = 0
        if (rank != 20 or (rank == 20 and stars > 1)):
            stars -= 1

    if (stars > rank_points[rank]):
        rank += 1
        stars = 1
        
    if (stars < 0):
        rank -= 1
        stars = rank_points[rank] -  1


print(rank)