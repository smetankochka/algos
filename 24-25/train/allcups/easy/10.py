data = {}
for _ in range(int(input())):
    w, c, *args = [int(x) for x in input().split()]
    for i in range(c):
        if args[2 * i] not in data:
            data[args[2 * i]] = (args[2 * i + 1], w)
        elif data[args[2 * i]] > (args[2 * i + 1], w):
            data[args[2 * i]] = (args[2 * i + 1], w)
for _ in range(int(input())):
    num, cost = [int(x) for x in input().split()]
    if num not in data:
        print(-1, -1)
    else:
        print(data[num][1], data[num][0] + cost)
