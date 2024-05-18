class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        // Kahn
        vector<int>* graph = new vector<int>[n];
        int* degree = new int[n]();

        for (int i = 0; i < edges.size(); i++) {
            int a_i = edges[i][0];
            int b_i = edges[i][1];

            graph[a_i].push_back(b_i);
            graph[b_i].push_back(a_i);
            degree[a_i] += 1;
            degree[b_i] += 1;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        while (n > 2) {
            for (int _ = leaves.size(); _ > 0; _--) {
                int v = leaves.front();
                leaves.pop();

                n--;

                for (int i = 0; i < graph[v].size(); i++) {
                    int u = graph[v][i];

                    degree[u] -= 1;

                    if (degree[u] == 1) {
                        leaves.push(u);
                    }
                }
            }
        }

        vector<int> root;
        while (!leaves.empty()) {
            root.push_back(leaves.front());
            leaves.pop();
        }

        return root;
    }
};
