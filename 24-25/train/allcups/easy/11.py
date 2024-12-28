n = sorted(list(input()))


def rec(s):
    if len(s) == 3:
        print(s)
        return
    for y in n:
        if y not in s:
            rec(s + y)


for x in n:
    rec(x)