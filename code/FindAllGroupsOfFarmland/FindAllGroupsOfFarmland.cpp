class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> coord;

        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (land[i][j] == 1) {
                    int ii, jj;
                    for (ii = i; ii < land.size() && land[ii][j] == 1; ii++) {
                        for (jj = j; jj < land[0].size() && land[ii][jj] == 1;
                             jj++) {
                            land[ii][jj] = 0;
                        }
                    }

                    coord.push_back({i, j, ii-1, jj-1});
                }
            }
        }

        return coord;
    }
};
