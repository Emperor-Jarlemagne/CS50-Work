import cs50 as cs

main()

def main():
    height = get_height()
    for i in range(n):
        print("#")

def get_height():
    while True:
        n = int(get_int("Height (between 1-8): \n"))
        n = range(1,8)
    else:
        print("Please Try Again")
    return n

