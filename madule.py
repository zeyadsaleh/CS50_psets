def checksum(cc_number):
    sum = 0
    while cc_number: # make the checksum of the card number
        last_num = cc_number % 10
        sum = sum + last_num
        cc_number = cc_number // 10
        sec_to_last_num = cc_number % 10
        sec_to_last_num = sec_to_last_num * 2
        digit = sec_to_last_num % 10
        sec_to_last_num = sec_to_last_num // 10
        sec_to_last_num = sec_to_last_num + digit
        sum = sum + sec_to_last_num
        cc_number = cc_number // 10
    return sum

def num_of_digits(cc_number):
    NumOfDegits = 0
    while cc_number:
        cc_number = cc_number // 10
        NumOfDegits += 1
    return NumOfDegits

def first_2_digits(cc_number):
    while (cc_number >= 100):
        cc_number = cc_number // 10
        first_2_digits = cc_number
    return first_2_digits

def first_digit (cc_number):
    while (cc_number >= 10):
        cc_number = cc_number // 10
        first_digit = cc_number

    return first_digit




