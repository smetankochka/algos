def max_dishes(n, m, d, weights, recipes):
    dish_weights = []
    for recipe in recipes:
        total_weight = sum(recipe[j] * weights[j] for j in range(m))
        dish_weights.append(total_weight)
    dish_weights.sort()
    count = 0
    current_weight = 0
    
    for weight in dish_weights:
        if current_weight + weight <= d:
            current_weight += weight
            count += 1
        else:
            break

    return count


n, m, d = map(int, input().split())
weights = list(map(int, input().split()))
recipes = [list(map(int, input().split())) for _ in range(n)]
result = max_dishes(n, m, d, weights, recipes)
print(result)