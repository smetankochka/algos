from math import ceil
n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
d = [int(x) for x in input().split()]
toplus = []
tominus = []
for i, elem in enumerate(a):
    if elem > 0:
        toplus.append(0)
        tominus.append(ceil((elem + 1) / b[i]) * d[i])
    elif elem < 0:
        tominus.append(0)
        toplus.append(ceil((abs(elem) + 1) / b[i]) * c[i])
    else:
        toplus.append(c[i])
        tominus.append(d[i])
dp =[[0] * (n + 1), [0] * (n + 1)]
dp[0][0] = 0
dp[1][0] = 1e18
for i in range(1, n + 1):
    dp[0][i] = min(dp[0][i - 1] + toplus[i - 1], dp[1][i - 1] + tominus[i - 1])
    dp[1][i] = min(dp[0][i - 1] + tominus[i - 1], dp[1][i - 1] + toplus[i - 1])
print(dp[0][n])
