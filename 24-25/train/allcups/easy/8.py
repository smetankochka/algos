n, m = [int(x) for x in input().split()]
s = set()
for x in [int(x) for x in input().split()]:
    s.add(x)
print(sorted(list(s))[-m])