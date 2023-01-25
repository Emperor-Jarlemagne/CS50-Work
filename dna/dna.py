import csv
from sys import argv, exit


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    with open(argv[1]) as strFile:
        reader = csv.reader(strFile)
        database = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(argv[2]) as dna:
        sequence = dna.read

    # TODO: Find longest match of each STR in DNA sequence
    matches = []

    for i in range(1, len(database[0])):
        matches.append = (longest_match(sequence, database[0][i]))
        print(matches)

    # TODO: Check database for matching profiles
    person = "No Match"
    counter = 0

    for i in range(1, len(database)):
        for j in range(len(matches)):
            if matches[j] == int(database[i][j + 1]):
                counter += 1
        if counter == len(matches):
            person = database[i][0]
            break
        else:
            counter = 0
    print(person)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
