n, m, k = [int(x) for x in input().split()]
mas = [int(x) for x in input().split()]
for _ in range(m):
    c, x = [int(x) for x in input().split()]
    mas.extend([x] * c)
mas.sort()
print(mas[k - 1])