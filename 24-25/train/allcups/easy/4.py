mod = int(1e9 + 7)
n = int(input())
a1 = n // 2
a2 = (n + 1) // 2
print(int((pow(3, a1, mod) + pow(3, a2, mod)) % mod))