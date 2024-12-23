n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()

for i in range(k):
    a[i] = max(abs(a[0]), abs(a[-1]))
print(sum(a))