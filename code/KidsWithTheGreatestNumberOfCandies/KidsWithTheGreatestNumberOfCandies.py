class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max = 0
        for i in candies:
            if i > max:
                max = i
        
        ans = []
        for i in candies:
            if i+extraCandies >= max:
                ans.append(True)
            else:
                ans.append(False)
        
        return ans
