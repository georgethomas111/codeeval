### To reverse a set of words in a line.
"""
Reverses a set of words in a line.
"""
def reverse(line) :
    words = line.split(' ')
    lineRet = ""

    for index in range(len(words)) :
        lineRet = lineRet + words.pop() + " "

    return lineRet[:-1]

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases : 
    if test :
        print reverse(test.strip())
test_cases.close()
