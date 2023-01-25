from cs50 import get_int

# Get Height as input from user (only between 2-8)
while True:
    height = get_int("Height: ")
    if height > 1 and height < 9:
        break

# Prints Spaces and Hashes respectively
spaces = 1
for j in range(height):
    for spaces in range(height - j - 1):
        print(" ", end="")
    for i in range(j + 1):
        print("#", end="")
    print()
