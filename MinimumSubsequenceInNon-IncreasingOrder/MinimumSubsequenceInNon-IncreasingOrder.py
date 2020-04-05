class Solution:
    def invQuickSort(self, arr, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        pivot = arr[left]
        while left < right:
            while left < right and arr[right] < pivot:
                right -= 1
            arr[left] = arr[right]
            while left < right and arr[left] >= pivot:
                left += 1
            arr[right] = arr[left]
        arr[left] = pivot
        
        self.invQuickSort(arr, begin, left-1)        
        self.invQuickSort(arr, left+1, end)
        
        return
    
    def minSubsequence(self, nums: List[int]) -> List[int]:
        length = len(nums)
        
        sums = sum(nums)
        
        self.invQuickSort(nums, 0, length-1)
        
        sum_subseq = 0
        
        for i in range(length):
            sum_subseq += nums[i]
            if sum_subseq > sums/2:
                break
                
        return nums[0:i+1]
