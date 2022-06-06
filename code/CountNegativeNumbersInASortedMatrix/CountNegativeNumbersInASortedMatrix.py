class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        neg = 0
        for i in grid:
            for j in i:
                if j < 0:
                    neg += 1
        return neg
