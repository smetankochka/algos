def nad_x(n, m, grid):
    meteor_coords = []
    surface_heights = [n] * m
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'M':
                meteor_coords.append((i, j))
            if grid[i][j] == '#' and surface_heights[j] == n:
                surface_heights[j] = i
    
    min_fall_distance = n
    for (i, j) in meteor_coords:
        fall_distance = surface_heights[j] - i - 1
        if fall_distance < min_fall_distance:
            min_fall_distance = fall_distance
    new_grid = [['.' for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '#':
                new_grid[i][j] = '#'
    
    for (i, j) in meteor_coords:
        new_grid[i + min_fall_distance][j] = 'M'
    
    return new_grid


n, m = map(int, input().split())
grid = [list(input().strip()) for _ in range(n)]
result = nad_x(n, m, grid)
for row in result:
    print("".join(row))