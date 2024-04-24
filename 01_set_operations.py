def create_set():
    return []

def add_to_set(s, element):
    if element not in s:
        s.append(element)

def remove_from_set(s, element):
    if element in s:
        s.remove(element)

def set_contains(s, element):
    return element in s

def set_size(s):
    return len(s)

def set_iterator(s):
    return iter(s)

def set_intersection(set1, set2):
    return [elem for elem in set1 if elem in set2]

def set_union(set1, set2):
    return list(set(set1 + set2))

def set_difference(set1, set2):
    return [elem for elem in set1 if elem not in set2]

def is_subset(set1, set2):
    return all(elem in set2 for elem in set1)

s1 = create_set()
add_to_set(s1, 1)
add_to_set(s1, 2)
add_to_set(s1, 3)

s2 = create_set()
add_to_set(s2, 2)
add_to_set(s2, 3)
add_to_set(s2, 4)

print("Set 1:", s1)
print("Set 2:", s2)

print("Intersection:", set_intersection(s1, s2))
print("Union:", set_union(s1, s2))
print("Difference (Set 1 - Set 2):", set_difference(s1, s2))
print("Is Set 1 a subset of Set 2?", is_subset(s1, s2))
