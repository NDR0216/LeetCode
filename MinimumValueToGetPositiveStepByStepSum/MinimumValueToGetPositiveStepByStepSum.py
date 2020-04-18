class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        n = len(nums)
        
        min = nums[0]
        
        sum = 0
        for i in range(n):
            sum += nums[i]
            
            if sum < min:
                min = sum
            
        if min < 0:
            return 1-min
        else:
            return 1
