class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> matrix(n, vector<int>(m));

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            matrix[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];

            if (rowSum[i] == 0) {
                i++;
            } 
            if (colSum[j] == 0) {
                j++;
            } 
        }

        return matrix;
    }
};
