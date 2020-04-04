class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        chars = {}
        
        for i in s:
            value = chars.get(i, 0)
            if value == 0:
                chars[i] = 1
            else:
                chars[i] = value+1
                
        pair = 0
        single = 0
        
        for value in chars.values():
            if value % 2 == 0:
                pair += value
            elif value % 2 == 1:
                single += 1
                pair += value-1
        
        if k < single or k-single > pair:
            return False
        else:
            return True
