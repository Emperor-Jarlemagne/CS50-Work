import cs50

letter_count = 0
word_count = 0
sentence_count = 0

text = input("Text: ")
length = len(text)

for i in range(length):
    #Count number of letters
    if (text[i].isalpha()):
        letter_count += 1
    #Count number of words
    if (text[i].isspace()):
        word_count += 1
    #Count number of sentences
    if (text[i] == "." or text[i] == "!" or text[i] == "?"):
        sentence_count += 1

formula = (0.0588 * letter_count / word_count * 100) - (0.296 * sentence_count / 100) - 15.8

index = round(formula)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
