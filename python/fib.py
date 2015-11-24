## Program to learn basic recursion
""" 
Start with fibanocci
"""

maxN = 20
saveFib = [0] * maxN

def fib(n) :
    if n >= maxN : 
        return fib(n-1) + fib(n-2)

    if saveFib[n] != 0 :
        return saveFib[n]

    if n == 1  or n == 2 :
        saveFib[n] = 1
    else :
        saveFib[n] = fib(n-1) + fib(n-2)
    return saveFib[n]

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases : 
    print str(fib(int(test))) 
test_cases.close()
