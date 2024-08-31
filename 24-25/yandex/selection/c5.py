def is_palindrome(num):
    return str(num) == str(num)[::-1]

def find_largest_palindrome_cube(N):
    max_y = int(N ** (1/3)) + 100
    max_palindrome_cube = -1

    for y in range(1, max_y + 1):
        cube = y ** 3
        if cube > N:
            break
        if is_palindrome(cube):
            max_palindrome_cube = max(max_palindrome_cube, cube)

    return max_palindrome_cube


N = int(input())
result = find_largest_palindrome_cube(N)
print(result)