// adjacency list
struct Edge {
    int idx;
    int dest;
    int weight;
};

void DFS(int v, bool* visited, vector<Edge>* graph, int* dist,
         vector<bool>* answer) {
    visited[v] = true;

    for (int i = 0; i < graph[v].size(); i++) {
        int idx = graph[v][i].idx;
        int u = graph[v][i].dest;
        int weight = graph[v][i].weight;

        if (dist[u] + weight == dist[v]) { // u -> v
            (*answer)[idx] = true;
            if (!visited[u]) {
                DFS(u, visited, graph, dist, answer);
            }
        }
    }
}

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<Edge>* graph = new vector<Edge>[n];
        for (int i = 0; i < edges.size(); i++) {
            int u_i = edges[i][0];
            int v_i = edges[i][1];
            int w_i = edges[i][2];

            graph[u_i].push_back({i, v_i, w_i});
            graph[v_i].push_back({i, u_i, w_i});
        }

        // Dijkstra
        int* dist = new int[n](); // shortest path to every node
        fill_n(dist, n, INT_MAX);

        // {dist[node], node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({dist[0], 0});

        while (!pq.empty()) {
            int dist_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if (dist_v > dist[v]) { // only first visit will be considered
                continue;
            }

            for (int i = 0; i < graph[v].size(); i++) {
                int u = graph[v][i].dest;
                int weight = graph[v][i].weight;

                int new_dist = dist[v] + weight;

                if (new_dist < dist[u]) {
                    dist[u] = new_dist;
                    pq.push({dist[u], u});
                }
            }
        }

        vector<bool> answer(edges.size());

        // DFS
        bool* visited = new bool[n]();
        if (dist[n - 1] != INT_MAX) {
            DFS(n - 1, visited, graph, dist, &answer);
        }

        return answer;
    }
};
