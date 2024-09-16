from itertools import permutations

def is_unsolvable(s1, s2, s3):
    unique_characters = set(s1 + s2 + s3)
    if len(unique_characters) > 10:
        return True
    return False

def create_number_from_string(s, mapping):
    return int(''.join(str(mapping[char]) for char in s))

def solve(s1, s2, s3):
    if is_unsolvable(s1, s2, s3):
        return "UNSOLVABLE"
    
    unique_chars = list(set(s1 + s2 + s3))
    for perm in permutations(range(10), len(unique_chars)):
        mapping = dict(zip(unique_chars, perm))
        if (mapping[s1[0]] == 0 or mapping[s2[0]] == 0 or mapping[s3[0]] == 0):
            continue
        
        n1 = create_number_from_string(s1, mapping)
        n2 = create_number_from_string(s2, mapping)
        n3 = create_number_from_string(s3, mapping)
        
        if n1 + n2 == n3:
            return f"{n1}\n{n2}\n{n3}"
    
    return "UNSOLVABLE"

s1 = input().strip()
s2 = input().strip()
s3 = input().strip()

print(solve(s1, s2, s3))