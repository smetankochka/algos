a, b, n, m = [int(x) for x in input().split()]
if n == m / 2:
    print(n, 0)
    exit(0)
kmax = min(n // a, m // b)
for k in range(1, kmax + 1):
    ostn = n - k * a
    ostm = m - k * b
    if ostn == ostm / 2:
        print(ostn, k)
        exit(0)
print(-1)