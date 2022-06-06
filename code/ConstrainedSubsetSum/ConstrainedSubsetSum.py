class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        sum = 0
        max = nums[0]
        
        i = 0
        while i < len(nums):
            max_local = nums[i]
            idx = 1
            for j in range(1, k+1):
                if i+j > n:
                    break
                elif nums[i+j-1] >= 0:
                    max_local = nums[i+j-1]
                    idx = j
                    break
                elif nums[i+j-1] > max_local:
                    max_local = nums[i+j-1]
                    idx = j
            
            if sum >= 0:
                sum += max_local
            else:
                sum = max_local
            i += idx
            
            if sum > max:
                max = sum
        return max
