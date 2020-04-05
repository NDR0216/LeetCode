class Solution:
    def numSteps(self, s: str) -> int:
        length = len(s)
        
        binary = list(s)
        
        step = 0
        overflow = 0
        
        i = length-1
        while i > 0:
            if binary[i] == '0':
                i -= 1
            else:
                j = i
                while binary[j] == '1':
                    binary[j] = '0'
                    if j > 0:
                        j -= 1
                    else:
                        overflow = 1
                if overflow == 0:
                    binary[j] = '1'
            step += 1
        
        step += overflow
        
        return step
