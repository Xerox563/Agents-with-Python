# dictionary basics
student = {"name": "Alice", "age": 20, "marks": 95}
print(student)

# access
print(student["name"])
print(student.get("marks"))
print(student.get("city", "Not Found"))

# add key-value
student["city"] = "Delhi"
print(student)

# update value
student["age"] = 21

# remove items
student.pop("marks")
print(student)

student["grade"] = "A"
student.popitem()   # removes last inserted
print(student)

# loop
for key in student:
    print(key)

for val in student.values():
    print(val)

for k, v in student.items():
    print(k, v)

# update multiple values
student.update({"age": 22, "country": "India"})
print(student)

# nested dictionary
students = {
    "s1": {"name": "Alice", "age": 20},
    "s2": {"name": "Bob", "age": 22}
}
print(students["s1"]["name"])

# dictionary comprehension
squares = {x: x*x for x in range(1, 6)}
print(squares)

# check key
print("age" in student)

# copy dictionary
d2 = student.copy()
print(d2)
