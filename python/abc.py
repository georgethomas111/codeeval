class swapBit(object) :
    def __init__(self) :
        self.a = [] 
        
    def add(self, elem) :
        self.a.append(elem)
        
    def __repr__(self) :
        return str(self.a)     
        
swapBitObj = swapBit()
swapBitObj.add(5)
print swapBitObj
