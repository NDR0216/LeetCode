class Solution:
    def quickSort(self, arr, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        pivot = arr[left]
        while left < right:
            while left < right and arr[right] >= pivot:
                right -= 1
            arr[left] = arr[right]
            while left < right and arr[left] < pivot:
                left += 1
            arr[right] = arr[left]
        arr[left] = pivot
        
        self.quickSort(arr, begin, left-1)        
        self.quickSort(arr, left+1, end)
        
        return
    
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        length = len(nums)
        original = nums.copy()
        ans = [0] * length
        
        self.quickSort(nums, 0, length-1)
        
        for i in range(length):
            ans[i] = nums.index(original[i])
        
        print(ans)
        
        return ans
        
