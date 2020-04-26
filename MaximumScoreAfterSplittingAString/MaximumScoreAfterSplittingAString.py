class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        
        zeros = []
        ones = []
        
        sum_zero = 0
        sum_one = 0
        for i in s:
            if i == '0':
                sum_zero += 1
            else:
                sum_one += 1
            zeros.append(sum_zero)
            ones.append(sum_one)
        
        max = 0
        for i in range(n-1):
            if zeros[i] + ones[n-1] - ones[i] > max:
                max = zeros[i] + ones[n-1] - ones[i]
                
        return max
