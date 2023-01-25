# How to arrange and sort a list of unstructured user inputs (in this case a list of TV shows)

import csv

titles = {} # empty curlybraces automatically defined as a dictionary

# "r" is to open file in read-mode
with open ("favourites.csv", "r") as file:
    reader = csv.DictReader(file)

# Skip first row on csv
    # next(reader)

    for row in reader:
        title = row["title"].strip().upper() # strip() will take off white spoace on either side of input AND I have added the function to turn answer into uppercase(added period!)
        # get at second column in row
        # print(row[1]) - for example
        if not title in titles:
            titles[title] = 0
        titles[title] += 1
        #if not title in titles:
            #titles.append(title) # add new title to list [titles]

# function returns VALUE of title (take title and return corresponding value)
#def get_value(title):
#    return titles[title]


for title in sorted(titles, key=lambda title: titles[title], reverse=True): # lambda function is an anonymous one line function to tighten up code - reverse=T is to reverse the order of list
    print(titles, titles[title])
