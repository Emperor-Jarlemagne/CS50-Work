import sys

numbers = [2, 6, 4, 8, 9, 0]

if 0 in numbers:
    print("Found!")
    sys.exit(0)

print("not found...")
sys.exit(1)

