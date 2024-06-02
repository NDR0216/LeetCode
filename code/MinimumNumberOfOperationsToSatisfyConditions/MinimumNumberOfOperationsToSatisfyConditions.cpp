class Solution {
private:
    static const int NUM_RANGE = 10;

public:
    int minimumOperations(vector<vector<int>>& grid) {
        int min_1st = 0;
        int min_1st_num = -1;
        int min_2nd;
        // int min_2nd_num; // never used

        for (int j = 0; j < grid[0].size(); j++) {
            int count[NUM_RANGE] = {0};
            for (int i = 0; i < grid.size(); i++) {
                count[grid[i][j]]++;
            }

            int next_min_1st = INT_MAX;
            int next_min_1st_num;
            int next_min_2nd = INT_MAX;
            // int next_min_2nd_num; // never used

            for (int num = 0; num < NUM_RANGE; num++) {
                int ops;
                if (num != min_1st_num) {
                    ops = min_1st + grid.size() - count[num];
                } else {
                    ops = min_2nd + grid.size() - count[num];
                }

                if (ops < next_min_1st) {
                    next_min_2nd = next_min_1st;
                    next_min_1st = ops;
                    next_min_1st_num = num;
                } else if (ops < next_min_2nd) {
                    next_min_2nd = ops;
                }
            }

            min_1st = next_min_1st;
            min_1st_num = next_min_1st_num;
            min_2nd = next_min_2nd;
        }

        return min_1st;
    }
};
