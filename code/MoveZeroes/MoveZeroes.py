class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        length = len(nums)
        zeros = 0
        
        i = 0
        while i < length:
            if nums[i] == 0:
                del nums[i]
                zeros += 1
                length -= 1
            else:
                i += 1
            
        for i in range(zeros):
            nums.append(0)
