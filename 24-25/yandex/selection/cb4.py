def rotate_90_clockwise(matrix):
    n = len(matrix)
    return [[matrix[n - 1 - j][i] for j in range(n)] for i in range(n)]

def normalize(mask):
    n = len(mask)
    while all(cell == '.' for cell in mask[0]):
        mask = mask[1:] + [['.'] * n]
    while all(cell == '.' for cell in mask[-1]):
        mask = [['.'] * n] + mask[:-1]
    while all(row[0] == '.' for row in mask):
        mask = [row[1:] + ['.'] for row in mask]
    while all(row[-1] == '.' for row in mask):
        mask = [['.'] + row[:-1] for row in mask]

    return mask

def are_same(mask_a, mask_b):
    for _ in range(4):
        mask_a = rotate_90_clockwise(mask_a)
        if normalize(mask_a) == normalize(mask_b):
            return True
    return False


n = int(input())
A = [list(input().strip()) for _ in range(n)]
B = [list(input().strip()) for _ in range(n)]
if are_same(A, B):
    print("YES")
else:
    print("NO")