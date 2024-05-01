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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        UnionFind uf(n);

        for (int i = 0; i < pairs.size(); i++) {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, vector<int>> idx;
        unordered_map<int, string> chars;

        for (int i = 0; i < n; i++) {
            int root = uf.find(i);

            idx[root].push_back(i);
            chars[root].push_back(s[i]);
        }

        for (unordered_map<int, string>::iterator it = chars.begin();
             it != chars.end(); ++it) {
            int key = it->first;
            string str = it->second;
            int length = it->second.size();

            sort(str.begin(), str.end());

            for (int i = 0; i < length; i++) {
                s[idx[key][i]] = str[i];
            }
        }

        return s;
    }
};
