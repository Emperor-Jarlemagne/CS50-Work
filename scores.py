# scores = [72, 73, 33]

from cs50 import get_int

score = []
 for i in range(3):
    score = get_int("Score: ")
    scores.append(score) # or! scores += [score]


average = sum(scores) / len(scores)
print(f"Average: {average}")
