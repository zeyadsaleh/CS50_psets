from cs50 import get_int
import madule as func


while True: # prompting the credit card number from the user
    cc_number = get_int("Number: ")
    if cc_number > 0:
        break

if (func.checksum(cc_number)) % 10 == 0:
    if (func.num_of_digits(cc_number)) == 16:
        if ((func.first_2_digits(cc_number)) == 51 or (func.first_2_digits(cc_number)) == 52 or (func.first_2_digits(cc_number)) == 53 or (func.first_2_digits(cc_number)) == 54 or (func.first_2_digits(cc_number)) == 55):
            print("MASTERCARD")
        elif ((func.first_digit(cc_number)) == 4):
            print("VISA")
        else:
            print("INVALID")
    if (func.num_of_digits(cc_number)) == 15:
        if ((func.first_2_digits(cc_number)) == 34 or (func.first_2_digits(cc_number)) == 37):
            print("AMEX")
        else:
            print("INVALID")
    if (func.num_of_digits(cc_number)) == 13:
        if ((func.first_digit(cc_number)) == 4):
            print("VISA")
        else:
            print("INVALID")
else:
    print("INVALID")









