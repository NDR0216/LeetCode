class Solution:
    n = 0
    k = 0
    str = []
    ans = ['']
    
    def recur(self, i):
        if i == self.n:
            self.k -= 1
            if self.k == 0:
                self.ans = list(self.str)
            return
        
        if i == 0:
            self.str.append('a')
            self.recur(i+1)
            del self.str[-1]
            self.str.append('b')
            self.recur(i+1)
            del self.str[-1]
            self.str.append('c')
            self.recur(i+1)
            del self.str[-1] 
        elif self.str[i-1] == 'a':
            self.str.append('b')
            self.recur(i+1)
            del self.str[-1]
            self.str.append('c')
            self.recur(i+1)
            del self.str[-1]
        elif self.str[i-1] == 'b':
            self.str.append('a')
            self.recur(i+1)
            del self.str[-1]
            self.str.append('c')
            self.recur(i+1)
            del self.str[-1]
        else:
            self.str.append('a')
            self.recur(i+1)
            del self.str[-1]
            self.str.append('b')
            self.recur(i+1)
            del self.str[-1]
            
        return
    
    def getHappyString(self, n: int, k: int) -> str:
        self.n = n
        self.k = k
        
        self.recur(0)
        
        ans_str = ''.join(self.ans)
        
        return ans_str
