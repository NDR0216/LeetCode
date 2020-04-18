class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        min_grid = [[None for i in range(m)] for j in range(n)] 
        
        for i in range(n):
            for j in range(m):
                up = -1
                left = -1
                if i > 0:
                    up = min_grid[i-1][j]
                if j > 0:
                    left = min_grid[i][j-1]
                    
                if up == -1 and left != -1:
                    min_grid[i][j] = left + grid[i][j]
                elif up != -1 and left == -1:
                    min_grid[i][j] = up + grid[i][j]
                elif up == -1 and left == -1:
                    min_grid[i][j] = grid[i][j]
                elif up < left:
                    min_grid[i][j] = up + grid[i][j]
                else:
                    min_grid[i][j] = left + grid[i][j]         
        
