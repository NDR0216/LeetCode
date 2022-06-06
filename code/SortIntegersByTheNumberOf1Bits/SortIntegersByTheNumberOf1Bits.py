class Solution:
    def quickSort(self, arr, ones, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        pivot = arr[left]
        ones_pivot = ones[left]
        while left < right:
            while left < right and (ones[right] > ones_pivot or (ones[right] == ones_pivot and arr[right] >= pivot)):
                right -= 1
            arr[left] = arr[right]
            ones[left] = ones[right]
            while left < right and (ones[left] < ones_pivot or (ones[left] == ones_pivot and arr[left] < pivot)):
                left += 1
            arr[right] = arr[left]
            ones[right] = ones[left]
        arr[left] = pivot
        ones[left] = ones_pivot
        
        self.quickSort(arr, ones, begin, left-1)        
        self.quickSort(arr, ones, left+1, end)
        
        return
    
    def sortByBits(self, arr: List[int]) -> List[int]:
        length = len(arr)
        ones = [0] * length
        for i, j in zip(arr, ones):
            temp = i
            while temp != 0:
                if temp%2 == 1:
                    j += 1
                temp = int(temp/2)
        
        self.quickSort(arr, ones, 0, length-1)
        return arr
