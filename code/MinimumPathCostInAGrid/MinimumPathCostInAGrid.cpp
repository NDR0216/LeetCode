class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = m-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int min = grid[i+1][0] + moveCost[grid[i][j]][0];
                for (int k = 0; k < n; k++) {
                    if (min > grid[i+1][k] + moveCost[grid[i][j]][k]) {
                        min = grid[i+1][k] + moveCost[grid[i][j]][k];
                    }
                }
                grid[i][j] += min; 
            }
        }
        
        int minPath = grid[0][0];
        for (int i = 0; i < n; i++) {
            if (minPath > grid[0][i]) {
                minPath = grid[0][i];
            }
        }
        
        return minPath;
    }
};
