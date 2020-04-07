class Solution:
    def findLucky(self, arr: List[int]) -> int:
        frequency = {};
        for i in arr:
            value = frequency.get(i, 0)
            frequency[i] = value+1
                
        ans = -1
        for key, value in frequency.items():
            if key == value and key > ans:
                ans = key
                    
        return ans
