class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Kahn
        vector<int>* graph = new vector<int>[n];
        int* indegree = new int[n]();

        for (int i = 0; i < edges.size(); i++) {
            int from_i = edges[i][0];
            int to_i = edges[i][1];

            graph[from_i].push_back(to_i);
            indegree[to_i] += 1;
        }

        queue<int> indegree_0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                indegree_0.push(i);
            }
        }

        unordered_set<int>* ancestors = new unordered_set<int>[n];

        while (!indegree_0.empty()) {
            int v = indegree_0.front();
            indegree_0.pop();

            for (int i = 0; i < graph[v].size(); i++) {
                int u = graph[v][i];

                ancestors[u].insert(ancestors[v].begin(), ancestors[v].end());
                ancestors[u].insert(v);

                indegree[u] -= 1;

                if (indegree[u] == 0) {
                    indegree_0.push(u);
                }
            }
        }

        vector<vector<int>> answer(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { // use the concept of counting sort
                if (ancestors[i].contains(j)) {
                    answer[i].push_back(j);
                }
            }
        }

        return answer;
    }
};
