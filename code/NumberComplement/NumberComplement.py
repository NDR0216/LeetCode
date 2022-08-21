class Solution:
    def findComplement(self, num: int) -> int:
        complement = 0
        
        n = 0
        while(num != 0):
            if num%2 == 0:
                complement += pow(2, n)
            num = int(num/2)
            n += 1
            
        return complement
