class NumMatrix {
public:
    int** sum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        sum = new int*[m];
        
        for (int i = 0; i < m; i++) {
            sum[i] = new int[n];
            
            int row_sum = 0;
            for (int j = 0; j < n; j++) {
                row_sum += matrix[i][j];
                if (i > 0) {
                    sum[i][j] = sum[i-1][j] + row_sum;
                } else {
                    sum[i][j] = row_sum;
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 > 0) {
            return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];
        } else if (row1 > 0 && col1 == 0) {
            return sum[row2][col2] - sum[row1-1][col2];
        } else if (row1 == 0 && col1 > 0) {
            return sum[row2][col2] - sum[row2][col1-1];
        } else {
            return sum[row2][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
