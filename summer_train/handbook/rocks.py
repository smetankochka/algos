#
# Created by smetanka on 21.07.2024.
#
n, m = [int(x) for x in input().split()]
if n % 2 == 0 and m % 2 == 0:
    print("Loose")
else:
    print("Win")