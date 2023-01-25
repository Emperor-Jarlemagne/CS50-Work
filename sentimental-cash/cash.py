from cs50 import get_float

# Keep track of Coins used
count = 0


while True:
    change = get_float("Change owed: \n")
    if change > 0:
        break
# round up to nearest
cent = round(change * 100)

#Track coins in order of Quarter, Dime, Nickel, Penny
while cent >= 25:
    cent = (cent - 25)
    count += 1
while cent >= 10:
    cent = (cent -10)
    count += 1
while cent >= 5:
    cent = (cent - 5)
    count += 1
while cent >= 1:
    cent = (cent - 1)
    count += 1

print(count)



