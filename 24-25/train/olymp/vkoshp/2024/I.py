n, m = [int(x) for x in input().split()]
pole = []
indexper = 0
maximum = 0
for i in range(n):
    pole.append(input())
    if pole[-1].count("#") > maximum:
        indexper = i
        maximum = pole[-1].count("#")

indexleft = 0
indexright = m
for i in range(m):
    if pole[indexper][i] == "#":
        indexleft = i
        break
for i in range(m - 1, -1, -1):
    if pole[indexper][i] == "#":
        indexright = i
        break

if pole[indexper + 1][indexleft] != "#" or pole[indexper - 1][indexleft] != "#":
    print("No")
    exit(0)
if pole[indexper + 1][indexright] != "#" or pole[indexper - 1][indexright] != "#":
    print("No")
    exit(0)
for i in range(indexper):
    for j in range(indexleft + 1, indexright):
        if pole[i][j] == "#":
            print("Yes")
            exit(0)
print("No")