"""
Convert excel column numbers to names 
26 -> Z
52 -> AZ

Constrainsts 
ZZZ is the max

There is no 0 only 1 - 26 

"""
"""
There is no concept of 0 here.

The remainder when we divide the number by 27 is actually the value
of the letter. 

Zero won't get in because  we have an explicit check for it. 

As zero is not there, the value can be flawed. 
Div/rem with 26
0/1 0/2 ...         0/25 1/0 1/1 ...  2/0
1 2 3 4 5 6 7 8 ... 25   26   27 .... 52
A B C D E F G H ...  Y    Z   AA .... AZ 
"""


def get_char(rem):
    return chr(ord('A') - 1 + rem)


def excel_name(number):
    """
    divide by 26 
    modulus by 26
    
    Handle special cases which are the cases where 0 happens to be there.
    """
    # ideally assert number != 0
    if number != 0:
        str_ret = ""
        while (number != 0):
            rem = number % 26  # remainder [0 - 25] 25 0 is Z and 25is Y A is 1
            number = number / 26

            if rem == 0:
                number = number - 1
                rem = rem = 26
            str_ret = get_char(rem) + str_ret

    return str_ret


def start():
    import sys
    test_cases = open(sys.argv[1], 'r')
    for test in test_cases:
        print(excel_name(int(test.strip())))
    test_cases.close()


start()
