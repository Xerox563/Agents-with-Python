# Statements
'''
A computer program is a list of "instructions" to be "executed" by a computer.
In a programming language, these programming instructions are called statements.

'''

# print("HEllow World !!",end="")

# print("Sorry , Hello Amit !!")
# print("I am",35,"Years Old !!")

# x=4.090
# print("Before TypeCasting ",type(x))
# y = int(x)
# print(y)
# print("After TypeCasting ",type(y));

# a= 34
# A=44
# print(a,A)  # Variables are case senstive
# _var =4;
# print(_var)

# # illegal Names
# # 2myvar = "John"
# # my-var = "John"
# # my var = "John"
# # print(2myvar,my-var,my var)

# # Camel Case : Each word, except the first, starts with a capital letter:
# myVariableName = "John"

# # Pascal Case : Each word starts with a capital letter: 
# MyVariableName = "Snow"

# #Snake Case : Each word is separated by an underscore character:
# my_variable_name = "The King"


# print(myVariableName,MyVariableName,my_variable_name)

# x,y,z = "Orange","Banana","Apple"
# print(x,y,z)

# Unpacking a Collection
# If you have a collection of values in a list, tuple etc. Python allows you to extract the values into variables. This is called unpacking.
# fruits= ["Orange","Banana","Apple"]
# x,y,z = fruits
# print(x,y,z)

# a = 6.7989
# b =8
# print(a * b)

# x = "awesome"

# def myFun():
#     x = "Amit"
#     print(x,"is",x)
# print(x)

# myFun()


# To change the value of a global variable inside a function, refer to the variable by using the global keyword:
def myFun():
    global x
    x ="Hello"

myFun()

print(x,"Python")
