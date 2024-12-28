a, b, c, d = [int(x) for x in input().split()]
data = [-1] * (b - a + 1)
for i in range(d):
    day, izm = [int(x) for x in input().split()]
    data[day - a] = izm
for i in range(b - a + 1):
    if i == 0 and data[i] == -1:
        print(a + i, -1)
        continue
    if a + i > c:
        print(a + i, -1)
        continue
    if data[i] == -1:
        data[i] = data[i - 1]
    print(a + i, data[i])