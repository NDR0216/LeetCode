class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        // Kahn
        vector<int>* graph = new vector<int>[n];
        int* indegree = new int[n]();

        for (int i = 0; i < edges.size(); i++) {
            int a_i = edges[i][0];
            int b_i = edges[i][1];

            graph[a_i].push_back(b_i);
            indegree[b_i] += 1;
        }

        queue<int> indegree_0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                indegree_0.push(i);
            }
        }

        int count = 0;
        int max_value = 0;
        unordered_map<char, int>* dp = new unordered_map<char, int>[n];

        while (!indegree_0.empty()) {
            int v = indegree_0.front();
            indegree_0.pop();

            count += 1;
            dp[v][colors[v]] += 1;

            max_value = max(max_value, dp[v][colors[v]]);

            for (int i = 0; i < graph[v].size(); i++) {
                int u = graph[v][i];

                for (unordered_map<char, int>::iterator it = dp[v].begin();
                     it != dp[v].end(); ++it) {
                    char key = it->first;
                    int value = it->second;

                    dp[u][key] = max(dp[u][key], value);
                }

                indegree[u] -= 1;

                if (indegree[u] == 0) {
                    indegree_0.push(u);
                }
            }
        }

        if (count != n) {
            return -1;
        }

        return max_value;
    }
};
