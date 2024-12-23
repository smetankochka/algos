left = {}
right = {}
s = input()
count = len(set(s))
c1, c2 = count, count
for i, elem in enumerate(s):
    if c1 == 0:
        break
    if elem not in left:
        left[elem] = i
        c1 -= 1
for i in range(len(s) - 1, -1, -1):
    if c2 == 0:
        break
    if s[i] not in right:
        right[s[i]] = i
        c2 -= 1
maxlen = 0
for key, val in right.items():
    if val - left[key] + 1 > maxlen:
        maxlen = val - left[key] + 1
print(maxlen)