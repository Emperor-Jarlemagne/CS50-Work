from cs50 import get_string

before = get_string("Before: ")
print("After: ", end="")
after = before.upper()
print(f"After: {after}")

#Alternative (slower) Option
#for c in before:
#    print(c.upper(), end="")
#print()