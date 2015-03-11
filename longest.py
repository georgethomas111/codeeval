### To find the longest N lines in a file.
"""
Finds the longest line among a set of lines in a file.
"""
class LongNTester(object) :

    def __init__(self, N) :
        self.N = N
        self._map = {} 
        self._maxN = -1
        self._minN = -1
        self.count = 0
        self.feedStated = False

    def feed(self, line) :
        lineLen = len(line)
        if lineLen not in self._map :
            self._map[lineLen] = []
            self._map[lineLen].append(line)
        else :
            self._map[lineLen].append(line)

    def getN(self) :
        self.topN = self._map.keys()
        self.topN = sorted(self.topN)
        topLines = []
        remain = True
        while(remain) :
            key = self.topN.pop()
            obj = self._map[key]

            if obj is None:
                remain = False
            elif ((N - len(topLines)) < len(obj)) :
                remain = False
                topLines.extend(obj[0:N-len(topLines)])
            else : 
                topLines.extend(obj)
        return topLines

    def debug(self) : 
        print self._map
        print self.topN
        print self._map.keys()
        print self.N

import sys
test_cases = open(sys.argv[1], 'r').readlines()
if test_cases[0] :
    N = int(test_cases[0])

longNTester = LongNTester(N)

for test in test_cases[1:] : 
    longNTester.feed(test.strip())

for line in longNTester.getN() :
    print line

