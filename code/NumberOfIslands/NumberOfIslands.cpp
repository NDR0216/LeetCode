struct Coord {
    int i, j;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // BFS
        queue<Coord> q;

        int island = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') { // initiate a new BFS
                    q.push({i, j});

                    while (!q.empty()) {
                        Coord p = q.front();
                        q.pop();

                        if (p.i >= 0 && p.i < grid.size() && p.j >= 0 &&
                            p.j < grid[0].size() && grid[p.i][p.j] == '1') {
                            grid[p.i][p.j] = '0';
                            q.push({p.i + 1, p.j});
                            q.push({p.i - 1, p.j});
                            q.push({p.i, p.j + 1});
                            q.push({p.i, p.j - 1});
                        }
                    }

                    island++;
                }
            }
        }

        return island;
    }
};
