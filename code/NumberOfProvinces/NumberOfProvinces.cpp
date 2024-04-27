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

    void unionSet(int x, int y) {
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
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j]) {
                    uf.unionSet(i, j);
                }
            }
        }

        return uf.num_root;
    }
};
