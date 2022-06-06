class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        max = nums[0]
        
        for i in nums:
            sum += i
            if sum > max:
                max = sum
            if i < 0 and sum < 0:
                sum = 0
                
        return max
