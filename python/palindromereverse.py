"""
Program to do reverse add
"""


def check_palindrome(num):
    """
    Returns true if the number is palindrome and false otherwise.
    """
    if num == get_rev(num):
        return True


def get_rev(num):
    """
    This returns the reverse of the number.

    takes ones digit 
    divide 
    """

    rev_num = 0

    while (num != 0):
        rem = num % 10
        num = num / 10
        rev_num = rev_num * 10 + rem

    return rev_num


def rev_add(ipnum, count=0):
    """
    takes an ipnum and returns the value when revadd becomes palindrome.
    """
    if count == 100:
        return (count, ipnum)
    if check_palindrome(ipnum):
        return (count, ipnum)

    count = count + 1

    num = ipnum + get_rev(ipnum)

    return rev_add(num, count)


def start():
    """
    Function that takes in the input and prints the output
    """
    import sys
    test_cases = open(sys.argv[1], 'r')
    for test in test_cases:
        (iter_count, palindrome) = rev_add(int(test.strip()))
        print iter_count, palindrome
    test_cases.close()


start()
