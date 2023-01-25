from cs50 import get_string

people = {
    "Canada": "+1-426-428-3496",
    "South AFrica": "+27 74-573-1094",
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")