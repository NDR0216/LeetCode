class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        max = 0
        
        i = 0
        while i <= max:
            if i == n-1:
                return True
            
            if i + nums[i] > max:
                max = i + nums[i]
            i += 1
        
        return False
