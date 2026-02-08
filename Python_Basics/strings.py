# =======================================================
# PYTHON STRINGS – COMPLETE NOTES + CODE IN ONE FILE
# =======================================================

# ----------------------------
# 1. BASIC STRING & MULTI-LINE
# ----------------------------

message = """This is a multi-line string."""
print(message)


# ----------------------------
# 2. INDEXING (Access characters)
# ----------------------------

def show_indexing(s):
    """
    Show how indexing works on a string.
    """
    print("First character:", s[0])
    print("Last character:", s[-1])


show_indexing("HelloWorld")


# ----------------------------
# 3. SLICING (Extract substrings)
# ----------------------------

def show_slicing(text):
    """
    Demonstrate slicing operations on a string.
    """
    print("Skip every 2nd character:", text[::2])     # step slicing
    print("Length:", len(text))
    print("From index 1 to n-1:", text[1 : len(text)-1])  # slicing


show_slicing("PythonIsGreatLanguage")


# ----------------------------
# 4. STRING FUNCTIONS
# ----------------------------

def string_functions(text):
    """
    Demonstrate basic string functions.
    """
    print("Length of string:", len(text))
    print("Uppercase:", text.upper())
    print("Lowercase:", text.lower())
    print("Capitalized:", text.capitalize())


string_functions("python language")


# ----------------------------
# 5. CHECKING CHARACTER TYPES
# ----------------------------

def check_characters(text):
    """
    Check different types of characters in a string.
    """
    print("Is Alphabet?:", text.isalpha())
    print("Is Digit?:", text.isdigit())
    print("Is Alphanumeric?:", text.isalnum())
    print("Is Lowercase?:", text.islower())
    print("Is Uppercase?:", text.isupper())


check_characters("abc123")


# ----------------------------
# 6. TRIM WHITESPACES
# ----------------------------

txt_spaces = "  dhqie9e 8ydqy9qey  "
print("Strip both sides:", txt_spaces.strip())
print("Left strip:", txt_spaces.lstrip())
print("Right strip:", txt_spaces.rstrip())


# ----------------------------
# 7. REPLACE CHARACTERS/WORDS
# ----------------------------

text = "I love Java"
print("Original:", text)
replaced_text = text.replace("Java", "Python")
print("Replaced:", replaced_text)


# ----------------------------
# 8. STRING IMMUTABILITY
# ----------------------------

text = "hello"
# Strings cannot be modified directly:
# text[0] = "H"   # ❌ ERROR

# Correct way:
text = "H" + text[1:]
print("After modification:", text)


# ----------------------------
# 9. SPLIT → Converts string to list
# ----------------------------

names = "Tom,Harry,Cullins".split(",")
print("Split result:", names)


# ----------------------------
# 10. JOIN → Converts list to string
# ----------------------------

words = ["Python", "is", "Fun"]
joined = " ".join(words)
print("Joined result:", joined)


# ----------------------------
# 11. FIND vs INDEX
# ----------------------------

text2 = "Python Programming"

print("Find 'Pro':", text2.find("Pro"))      # returns index
print("Find 'Java':", text2.find("Java"))    # returns -1

print("Index 'Pro':", text2.index("Pro"))    # returns index
# print(text2.index("Java"))  # ❌ ERROR (uncomment to see error)


# ----------------------------
# 12. F-STRING FORMATTING
# ----------------------------

name = "Alice"
age = 20

print(f"My name is {name} and I am {age} years old.")


# ----------------------------
# 13. COUNT OCCURRENCES
# ----------------------------

print("Count 'P' in text2:", text2.count("P"))


# ----------------------------
# 14. REVERSE STRING
# ----------------------------

def reverse_string(s):
    """
    Return the reversed version of a string.
    """
    return s[::-1]


print("Reversed string:", reverse_string("Python"))


