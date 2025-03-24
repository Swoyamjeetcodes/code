print("Hello world")
# single line comment
"""multi line comment"""
"""Python has no command for declaring a variable.
A variable is created the moment you first assign a value to it"""
x = 5
y = "John"  # string
print(x)
print(y)
x = str(3)
print(type(x))
x, y, z = "Orange", "Banana", "Cherry"  # multiple variables
print(x)
print(y)
print(z)
print(x, y, z)  # multiple variables printing
x = "python"
y = " is awesome"
print(x + y)  # string concatenation

# To create a global variable inside a function, you can use the global keyword.
def myfunc():
    global x  # global variable
    x = "fantastic"

myfunc()
print("Python is " + x)

# Built-in Data Types
x = "Hello World"  # str
x = 20  # int
x = 20.5  # float
x = 1j  # complex
x = ["apple", "banana", "cherry"]  # list
x = ("apple", "banana", "cherry")  # tuple
x = range(6)  # range
x = {"name": "John", "age": 36}  # dict
x = {"apple", "banana", "cherry"}  # set
x = frozenset({"apple", "banana", "cherry"})  # frozenset
x = True  # bool
x = b"Hello"  # bytes
x = bytearray(5)  # bytearray
x = memoryview(bytes(5))  # memoryview
x = None  # NoneType

import random
print("randome number = ",random.randrange(1, 10)) # random number

k="banana"
for x in k:
  print(x)
print(len(k)) # length of string

# Check if "free" is present in the following text:
txt = "The best things in life are free!"
print("free" in txt)  # in operator

if "expensive" not in txt: # not in operator
  print("No, 'expensive' is NOT present.")

# Slicing
b = "Hello, World!"
print(b[2:5])  # slicing
print(b[:5])  # slice from start
print(b[2:])  # slice to end
print(b[-5:-2])  # negative indexing

# Modify Strings
a = "Hello, World!"
print(a.upper())  # upper case
print(a.lower())  # lower case
print(a.strip())  # remove whitespace
print(a.replace("H", "J"))  # replace string
print(a.split(","))  # split string

#format strings
age = 36
txt = f"My name is John, and I am {age}" # format string using f
txt = f"My name is John, and I am {age:.2f}" # format string using f
print(txt)

# Escape Characters
txt = "We are the so-called \"Vikings\" from the north."  # Double Quote
print(txt)
txt = 'It\'s alright.'  # Single Quote
print(txt)
txt = "This will insert one \\ (backslash)."  # Backslash
print(txt)
txt = "Hello\nWorld!"  # New Line
print(txt)
txt = "Hello\tWorld!"  # Tab
print(txt)
txt = "Hello\rWorld!"  # Carriage Return
print(txt)
txt = "Hello\bWorld!"  # Backspace
print(txt)
txt = "Hello\fWorld!"  # Form Feed
print(txt)
txt = "Hello\u0041World!"  # Unicode
print(txt)
txt = "Hello\x41World!"  # Hexadecimal
print(txt)
txt = "Hello\000World!"  # Octal
print(txt)

x = 2
y = 5
print(x ** y)  # Exponentiation

x = 15
y = 2
print(x // y) # Floor division

# list 
thislist = ["apple", "banana", "cherry"]
print(thislist)
"""
List is a collection which is ordered and changeable. Allows duplicate members.
Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
Set is a collection which is unordered, unchangeable*, and unindexed. No duplicate members.
Dictionary is a collection which is ordered** and changeable. No duplicate members.
"""
thislist = ["apple", "banana", "cherry"]
thislist.insert(2, "watermelon") # insert
print(thislist)

# list comprehension
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = [x for x in fruits if "a" in x]
print(newlist)
# newlist = [expression for item in iterable if condition == True]
