class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination) {
            return true;
        }

        // adjacency list
        vector<int>* graph = new vector<int>[n];

        for (int i = 0; i < edges.size(); i++) {
            int u_i = edges[i][0];
            int v_i = edges[i][1];

            graph[u_i].push_back(v_i);
            graph[v_i].push_back(u_i);
        }

        // DFS
        stack<int> s;
        bool* visited = new bool[n]();

        visited[source] = true;
        s.push(source);

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
                int u = *it;

                if (u == destination) {
                    return true;
                }

                if (!visited[u]) {
                    visited[u] = true;
                    s.push(u);
                }
            }
        }

        return false;
    }
};
