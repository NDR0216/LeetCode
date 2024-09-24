struct Coord {
    int x, y;
};

class Solution {
private:
    static const int SIZE = 50;

public:
    int memo(int** dp, unsigned int bitmask, int pos, int** cost,
             vector<vector<int>>& positions) {
        if (dp[bitmask][pos] != 0) {
            return dp[bitmask][pos];
        }

        int turn = popcount(bitmask);

        if (turn == positions.size() - 1) { // all pawn has been captured
            return 0;
        }

        if (turn % 2 == 1) {
            dp[bitmask][pos] = INT_MAX;
        } else {
            dp[bitmask][pos] = 0;
        }

        for (int i = 0; i < positions.size() - 1; i++) {
            if ((bitmask & (1 << i)) == 0) { // unvisited
                int temp = memo(dp, bitmask | (1 << i), i, cost, positions) +
                           cost[pos][i];

                if (turn % 2 == 1) {
                    dp[bitmask][pos] = min(dp[bitmask][pos], temp);
                } else {
                    dp[bitmask][pos] = max(dp[bitmask][pos], temp);
                }
            }
        }

        return dp[bitmask][pos];
    }

    // helper fn for BFS
    void visit(int x, int y, int moves, int temp[][SIZE], queue<Coord>* q) {
        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) {
            return;
        }

        if (temp[x][y] == -1) {
            temp[x][y] = moves;
            q->push({x, y});
        }
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        // 16*2500*8 = 3.2e5
        // dp[bitmask][pos]: (1<<15)*16*16=8.3e6

        positions.push_back({kx, ky}); // treat original pos as another pawn

        int** cost = new int*[positions.size()];
        for (int i = 0; i < positions.size(); i++) {
            cost[i] = new int[positions.size()]();
        }

        // BFS
        for (int i = 0; i < positions.size(); i++) {
            int temp[SIZE][SIZE] = {};
            fill(&temp[0][0], &temp[0][0] + SIZE * SIZE, -1); // -1: unvisited

            int x_i = positions[i][0];
            int y_i = positions[i][1];

            queue<Coord> q;

            temp[x_i][y_i] = 0; // visited
            q.push({x_i, y_i});

            int moves = 1;
            while (!q.empty()) {
                for (int _ = q.size(); _ > 0; _--) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();

                    visit(x + 2, y + 1, moves, temp, &q);
                    visit(x + 2, y - 1, moves, temp, &q);
                    visit(x - 2, y + 1, moves, temp, &q);
                    visit(x - 2, y - 1, moves, temp, &q);
                    visit(x + 1, y + 2, moves, temp, &q);
                    visit(x + 1, y - 2, moves, temp, &q);
                    visit(x - 1, y + 2, moves, temp, &q);
                    visit(x - 1, y - 2, moves, temp, &q);
                }

                moves++;
            }

            for (int j = 0; j < positions.size(); j++) {
                int x = positions[j][0];
                int y = positions[j][1];

                cost[i][j] = temp[x][y];
            }
        }

        // dp[bitmask][pos], bitmask 00...00 means all uncaptured
        int** dp = new int*[1 << (positions.size() - 1)];
        for (int i = 0; i < 1 << (positions.size() - 1); i++) {
            dp[i] = new int[positions.size()]();
        }

        return memo(dp, 0, positions.size() - 1, cost, positions);
    }
};
