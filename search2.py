import csv

from cs50 import SQL

 db = SQL ("sqlite:///favorites.db") #URI - something that kooks like a URL but actually opens up an address in a database

 title = input("Title: ").strip()

 rows = db.execute("SELECT COUNT (*) FROM favorites WHERE title LIKE ?", title) # In this case the ? is like %s in C (placeholder for title[in this case anyway], defined after comma)

for row in rows:
    print(row["title"])

