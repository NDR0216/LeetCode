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
    
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n = len(satisfaction)
        
        self.quickSort(satisfaction, 0, n-1)
        
        max = 0
        for i in range(n):
            likeTime = 0
            for j in range(0, n-i):
                likeTime += satisfaction[j] * (j+1)
            del satisfaction[0]
            
            if likeTime > max:
                max = likeTime
                
        return max
