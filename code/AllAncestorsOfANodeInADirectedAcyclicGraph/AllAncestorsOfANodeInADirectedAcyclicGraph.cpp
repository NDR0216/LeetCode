class Solution {
public:
    void DFS(int src, int v, vector<vector<int>>* answer, vector<int>* graph) {
        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];

            if ((*answer)[u].empty() || (*answer)[u].back() != src) {
                (*answer)[u].push_back(src);
                DFS(src, u, answer, graph);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // adjacency list
        vector<int>* graph = new vector<int>[n];
        for (int i = 0; i < edges.size(); i++) {
            int from_i = edges[i][0];
            int to_i = edges[i][1];

            graph[from_i].push_back(to_i);
        }

        vector<vector<int>> answer(n);
        for (int i = 0; i < n; i++) {
            DFS(i, i, &answer, graph);
        }

        return answer;
    }
};
