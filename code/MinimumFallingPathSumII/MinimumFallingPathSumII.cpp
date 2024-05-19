class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int min_1st = 0;
        int min_1st_idx = -1;
        int min_2nd;
        // int min_2nd_idx; // never used

        for (int i = 0; i < n; i++) {
            int next_min_1st = INT_MAX;
            int next_min_1st_idx;
            int next_min_2nd = INT_MAX;
            // int next_min_2nd_idx; // never used

            for (int j = 0; j < n; j++) {
                int sum;
                if (j != min_1st_idx) {
                    sum = min_1st + grid[i][j];
                } else {
                    sum = min_2nd + grid[i][j];
                }

                if (sum < next_min_1st) {
                    next_min_2nd = next_min_1st;
                    next_min_1st = sum;
                    next_min_1st_idx = j;
                } else if (sum < next_min_2nd) {
                    next_min_2nd = sum;
                }
            }

            min_1st = next_min_1st;
            min_1st_idx = next_min_1st_idx;
            min_2nd = next_min_2nd;
        }

        return min_1st;
    }
};
