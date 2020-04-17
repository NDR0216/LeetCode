class Solution:
    grid = [[None]]
    n = 0
    m = 0
    
    def island(self, i, j):
        if i > 0 and self.grid[i-1][j] == '1':
            self.grid[i-1][j] = '2'
            self.island(i-1, j)
        if i < self.n-1 and self.grid[i+1][j] == '1':
            self.grid[i+1][j] = '2'
            self.island(i+1, j)
        if j > 0 and self.grid[i][j-1] == '1':
            self.grid[i][j-1] = '2'
            self.island(i, j-1)
        if j < self.m-1 and self.grid[i][j+1] == '1':
            self.grid[i][j+1] = '2'
            self.island(i, j+1)
        
    
    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        self.n = len(grid)
        if grid != []:
            self.m = len(grid[0])
        else:
            return 0
        
        cnt = 0
        
        for i in range(self.n):
            for j in range(self.m):
                if self.grid[i][j] == '1':
                    self.island(i, j)
                    cnt += 1
