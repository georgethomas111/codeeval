### To get the mth element from last
"""
Simple program to print the mth element from the end.
"""
def mElem(line) :
    words = line.split(' ')
    m = int(words.pop())
    try :
        return (True, words[-m])
    except IndexError :
        return (False, -1)

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases : 
    if test :
        result = mElem(test.strip())
        if result[0] is True : 
            print result[1]
test_cases.close()
