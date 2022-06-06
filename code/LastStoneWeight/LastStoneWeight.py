class Solution:
    def invQuickSort(self, arr, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        
        pivot = arr[begin]
        
        while left < right:
            while left < right and pivot >= arr[right]:
                right -= 1
            arr[left] = arr[right]
            while left < right and pivot < arr[left]:
                left += 1
            arr[right] = arr[left]
            
                
        arr[left] = pivot
            
        self.invQuickSort(arr, begin, left-1)
        self.invQuickSort(arr, left+1, end)
        return
    
    def sort(self, arr, num):
        for i in arr:
            if num > i:
                arr.insert(i-1, num)
                return
            
        arr.append(num)
        return
        
    def lastStoneWeight(self, stones: List[int]) -> int:
        n = len(stones)
        self.invQuickSort(stones, 0, n-1)
        
        while len(stones) > 1:
            a = stones[0]
            del stones[0]
            
            b = stones[0]
            del stones[0]
            
            diff = a-b
            if diff > 0:
                stones.append(diff)
                self.invQuickSort(stones, 0, len(stones)-1)
        
        if len(stones) == 1:
            return stones[0]
        else:
            return 0
