class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = [None] * 5
        self.head = -1
        self.cap = 5
        
    def push(self, x: int) -> None:
        if self.head >= 0:
            mins = min(x, self.data[self.head][1])
        else:
            mins = x
        
        self.head += 1
        if self.head >= self.cap:
            self.doubleCap()
        self.data[self.head] = (x, mins)
        return
        
    def pop(self) -> None:
        self.head -= 1
        return

    def top(self) -> int:
        return self.data[self.head][0]

    def getMin(self) -> int:
        return self.data[self.head][1]
    
    def doubleCap(self):
        self.data.extend([None] * self.cap)
        self.cap *= 2
        return
