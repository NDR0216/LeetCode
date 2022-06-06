class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        
        sums = []
        
        sum = 0
        for i in cardPoints:
            sum += i
            sums.append(sum)
            
        min = sums[n-k-1]
        
        for i in range(k):
            if sums[i+n-k] - sums[i] < min:
                min = sums[i+n-k] - sums[i]
                
        return sums[n-1] - min
