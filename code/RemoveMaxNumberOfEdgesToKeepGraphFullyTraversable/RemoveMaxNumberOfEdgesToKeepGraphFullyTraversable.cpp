class UnionFind {
private:
    int *root, *rank;

public:
    int num_root;

    UnionFind(int n) {
        root = new int[n]; // root array
        rank = new int[n]();
        num_root = n;

        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x != root[x]) { // x is not the root node
            root[x] = find(root[x]);
        }

        return root[x];
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            num_root--;

            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }

            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf1(n);
        UnionFind uf2(n);

        int cnt = 0;
        for (int i = 0; i < edges.size(); i++) {
            int type_i = edges[i][0];
            int u_i = edges[i][1] - 1;
            int v_i = edges[i][2] - 1;

            if (type_i == 3) {
                cnt += uf1.unionSet(u_i, v_i);
                uf2.unionSet(u_i, v_i);
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int type_i = edges[i][0];
            int u_i = edges[i][1] - 1;
            int v_i = edges[i][2] - 1;

            if (type_i == 1) {
                cnt += uf1.unionSet(u_i, v_i);
            } else if (type_i == 2) {
                cnt += uf2.unionSet(u_i, v_i);
            }
        }

        if (uf1.num_root != 1 || uf2.num_root != 1) {
            return -1;
        }

        return edges.size() - cnt;
    }
};
