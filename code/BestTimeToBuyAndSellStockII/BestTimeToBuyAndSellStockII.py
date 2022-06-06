class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        if len(prices) == 0:
            return 0
        
        max = prices[0]
        min = prices[0]
        
        profit = 0
        
        for i in prices:
            if i > max:
                max = i
            else:
                profit += (max-min)
                max = i
                min = i
        
        profit += (max-min)
        
        return profit
