### Converts to lower case
"""
To Lower
"""
import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases : 
    print test.strip().lower()
test_cases.close()
