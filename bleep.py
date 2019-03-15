from cs50 import get_string
from sys import argv, exit

def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    words = set()
    file = open(argv[1], "r")
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()
    message = get_string("What message would you like to censor?\n")
    tokens = message.split()
    for word in tokens:
        lower = word.lower()
        if lower in words:
            x = word.replace(word , "*" * len(word))
            print(x, end=" ")
        else:
            print(word, end=" ")
    print()

if __name__ == "__main__":
    main()
