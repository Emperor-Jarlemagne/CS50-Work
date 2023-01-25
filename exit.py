from sys import argv

if len(argv) != 2:
    print("Missing Command-Line Argument")
    exit(1)

print(f"Hello, {argv[1]}")
exit(0)
