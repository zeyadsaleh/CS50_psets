from sys import argv
from cs50 import get_string

if len(argv) != 2:
    print("Usage: python caesar.py k")
k = int(argv[1])
if k != 0:
    p = get_string("plaintext: ")
    print("ciphertext: ", end="")
    for c in p:
        if c.isalpha():
            if c.isupper():
                u = (((ord(c) - 65) + k) % 26) + 65
                print(chr(u), end="")
            else:
                l = (((ord(c) - 97) + k) % 26) + 97
                print(chr(l), end="")
        else:
            print(c, end="")
    print()

else:
    print("Usage: python caesar.py k")

