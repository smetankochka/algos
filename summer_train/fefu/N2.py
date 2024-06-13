with open('input.txt', 'r') as f:
    text = f.readline().strip()
    N = int(f.readline())
    words = [f.readline().strip() for _ in range(N)]   # список хранящий все слова, которые надо проверить

result = []
for word in words:   # с помощью in проверяем каждое слово есть ли оно в исходной строке
    if word in text:
        result.append(1)
    else:
        result.append(0)

with open('output.txt', 'w') as f:
    f.write(' '.join(map(str, result)))
