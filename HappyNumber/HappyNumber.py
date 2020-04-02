class Solution:
    def isHappy(self, n: int) -> bool:
        process = []
        while n not in process:
            process.append(n)
            sqrs = 0
            while n != 0:
                sqrs += (n%10)**2
                n = int(n/10)
                
            if sqrs == 1:
                return True
            n = sqrs
        return False
