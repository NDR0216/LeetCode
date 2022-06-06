class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        power = 0
        
        AND = 0
        while m != 0 and n!= 0:
            if n == m and n%2 == 1:
                AND += pow(2, power)
            
            power += 1
            m = int(m/2)
            n = int(n/2)
        
        return AND
