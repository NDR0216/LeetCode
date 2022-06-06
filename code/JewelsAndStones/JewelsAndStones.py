class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        jewel = 0
        for i in J:
            for j in S:
                if i == j:
                    jewel += 1
        
        return jewel
