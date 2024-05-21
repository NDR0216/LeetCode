class UnionFind {
private:
    int *root, *rank;

public:
    int* cost;

    UnionFind(int n) {
        root = new int[n]; // root array
        rank = new int[n]();
        cost = new int[n];

        for (int i = 0; i < n; i++) {
            root[i] = i;
            cost[i] = -1;
        }
    }

    int find(int x) {
        if (x != root[x]) { // x is not the root node
            root[x] = find(root[x]);
        }

        return root[x];
    }

    void unionSet(int x, int y, int weight) {
        int rootX = find(x);
        int rootY = find(y);

        cost[rootX] = cost[rootY] = cost[rootX] & cost[rootY] & weight;

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        UnionFind uf(n);

        for (int i = 0; i < edges.size(); i++) {
            int u_i = edges[i][0];
            int v_i = edges[i][1];
            int w_i = edges[i][2];

            uf.unionSet(u_i, v_i, w_i);
        }

        vector<int> cost(query.size());
        for (int i = 0; i < query.size(); i++) {
            int s_i = query[i][0];
            int t_i = query[i][1];

            int rootS = uf.find(s_i);
            int rootT = uf.find(t_i);

            if (rootS != rootT) {
                cost[i] = -1;
            } else {
                cost[i] = uf.cost[rootS];
            }
        }

        return cost;
    }
};
