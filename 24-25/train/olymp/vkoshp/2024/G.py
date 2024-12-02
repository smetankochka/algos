a = int(input())
b = int(input())
if a == b:
    print(0)
elif a == 0:
    if b > 0:
        print(b)
    else:
        print(abs(b) + 1)
elif b == 0:
    if a > 0:
        print(a + 1)
    else:
        print(abs(a))
elif a > 0 and b > 0:
    if b > a:
        print(b - a)
    else:
        print(a - b + 2)
elif a < 0 and b < 0:
    if b > a:
        print(b - a)
    else:
        print(a - b + 2)
elif a >= 0 and b < 0:
    print(abs(abs(b) - a) + 1)
else:
    print(1 + abs(b - abs(a)))