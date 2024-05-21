class Solution {
public:
    bool check(const vector<int>& queen, int col, int row) {
        // check queen[0:row-1]
        for (int i = 0; i < row; i++) {
            if (queen[i] == col) {
                return false;
            }
            if (abs(queen[i] - col) == row - i) { // diagonal
                return false;
            }
        }
        return true;
    }

    void solveNQueens_(int n, int row, vector<int>* queen,
                       vector<vector<string>>* sol) {
        if (row == n) {
            vector<string> new_sol(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                new_sol[i][(*queen)[i]] = 'Q';
            }
            sol->push_back(new_sol);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(*queen, i, row)) {
                (*queen)[row] = i;
                solveNQueens_(n, row + 1, queen, sol);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<int> queen(n);

        solveNQueens_(n, 0, &queen, &sol);

        return sol;
    }
};
