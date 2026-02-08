"""
List : Collection of multiple items stored in a single variable.
- ordered (indexing works)
- mutable
- dynamic
- can store numbers, strings, floats, booleans, other lists
"""

fruits = ["apple", "banana", "mango"]
print(fruits[0])   # first item
print(fruits[-1])  # last item

# append
fruits.append("Guava")
print(fruits)

# insert at index
fruits.insert(1, "Orange")
print(fruits)

# slicing
arr = [10, 20, 30, 40, 50]
print(arr[1:4])   # 20,30,40
print(arr[:3])    # 10,20,30
print(arr[::-1])  # reverse list

# remove specific element
arr.remove(20)
print(arr)

# pop -> removes and returns last element
x = arr.pop()
print(x)
print(arr)

# sort
arr.sort()
print(arr)

# reverse
arr.reverse()
print(arr)

# extend list
brr = [90, 80, 70]
arr.extend(brr)
print(arr)

# loop
for x in arr:
    print(x)

# enumerate loop
for i, x in enumerate(arr):
    print(i, x)

# list comprehension
squares = [x * x for x in range(1, 6)]
print(squares)
