for _ in range(int(input())):
    _ = int(input())
    if "".join(sorted(list(input()))) < "".join(sorted(list(input()), reverse=True)):
        print("Yes")
    else:
        print("No")