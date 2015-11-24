"""Sample code to read in test cases:

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    # ignore test if it is an empty line
    # 'test' represents the test case, do something with it
    # ...
    # ...

test_cases.close()
"""


def clear_rep(str_entry) :
   
    if len(str_entry) == 0 : 
        return str_entry

    prev_char = ""
    
    index = 0
    while(index < len(str_entry)) :
        char = str_entry[index]
        if char == prev_char :
           str_entry = str_entry[0:index] + str_entry[index + 1 :]
        else :
           index = index + 1
        prev_char = str_entry[index - 1]

    return str_entry
            
import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    print test
    print clear_rep(test.strip())
    # ignore test if it is an empty line
    # 'test' represents the test case, do something with it
    # ...
    # ...

test_cases.close()
