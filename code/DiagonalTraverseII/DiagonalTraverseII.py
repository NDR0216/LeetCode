class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        diagonals = [[]]
        
        for i in range(n):
            for j in range(len(nums[i])):
                diagonals.append([])
                diagonals[i+j].insert(0, nums[i][j])
        
        ans = []
        for i in diagonals:
            ans.extend(i)
            
        return ans
