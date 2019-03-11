from cs50 import get_int

while(True): # promt the user for valid number
    height = get_int("Height: ")
    if height <= 8 and height > 0:
        break

for i in range (height): # print the half pyramid
    print(" " * (height - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1))

