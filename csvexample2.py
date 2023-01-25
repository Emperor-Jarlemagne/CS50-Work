import csv
import re # Regular Expression library

counter = 0

with open ("favourites.csv", "r") as file: # We dont have access to this csv but it is a list of favourite TV shows
    reader = csv.DictReader (file)
    for row in reader:
        title = row["title"].strip().upper() # For each entry in the row, strip of white space, and make uppercase
        #if title == "THE OFFICE": # in this example we are looking for how many occurences of "the office" are in "favourites.csv"
        if re.search("^(OFFICE|THE.OFFICE)$", title): # use search function from RE library to look for string "office" in title
            counter += 1

print(f"Number of people who like The Office: {counter}")

