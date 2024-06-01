template <> struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        // copy from boost::hash_combine
        size_t x = hash<int>{}(p.first) + 0x9e3779b9 + hash<int>{}(p.second);
        const size_t m = 0xe9846af9b1a615d;
        x ^= x >> 32;
        x *= m;
        x ^= x >> 32;
        x *= m;
        x ^= x >> 28;
        return x;
    }
};

class Solution {
public:
    bool visit(int row, int col, int x, int y,
               unordered_set<pair<int, int>>& visited1,
               unordered_set<pair<int, int>>& visited2,
               queue<pair<int, int>>* q) {
        row = abs(row);
        col = abs(col);

        if (row < col) {
            swap(row, col);
        }

        if (row >= x + 2 || col >= y + 2) {
            return false;
        }

        if (visited1.find({row, col}) == visited1.end()) { // not found
            visited1.insert({row, col});
            q->push({row, col});
        }

        return visited2.find({row, col}) != visited2.end();
    }

    int minKnightMoves_(int x, int y) { // x >= y
        if (x == 0 && y == 0) {
            return 0;
        }

        unordered_set<pair<int, int>> visited1;
        unordered_set<pair<int, int>> visited2;
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        // visit (0, 0)
        visited1.insert({0, 0});
        visited2.insert({x, y});
        q1.push({0, 0});
        q2.push({x, y});

        int steps = 1;
        while (!q1.empty()) {
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(visited1, visited2);
            }

            for (int _ = q1.size(); _ > 0; _--) {
                int p_x, p_y;
                tie(p_x, p_y) = q1.front();
                q1.pop();

                // return if found
                if (visit(p_x + 2, p_y + 1, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x + 2, p_y - 1, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x - 2, p_y + 1, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x - 2, p_y - 1, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x + 1, p_y + 2, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x + 1, p_y - 2, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x - 1, p_y + 2, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
                if (visit(p_x - 1, p_y - 2, x, y, visited1, visited2, &q1)) {
                    return steps;
                }
            }
            steps++;
        }

        return -1;
    }

    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        if (x < y) {
            swap(x, y);
        }

        return minKnightMoves_(x, y);
    }
};
