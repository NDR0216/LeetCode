struct Edge {
    int dest;
    int weight;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<Edge>* graph = new vector<Edge>[n];
        for (int i = 0; i < times.size(); i++) {
            int u_i = times[i][0] - 1;
            int v_i = times[i][1] - 1;
            int w_i = times[i][2];

            graph[u_i].push_back({v_i, w_i});
        }

        int* dist = new int[n](); // shortest path to every node
        fill_n(dist, n, INT_MAX);

        // (dist[node], node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[k - 1] = 0;
        pq.push({dist[k - 1], k - 1});

        while (!pq.empty()) {
            int dist_v, v;
            tie(dist_v, v) = pq.top();
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

        int delay = 0;
        for (int i = 0; i < n; i++) {
            delay = max(delay, dist[i]);
        }

        if (delay == INT_MAX) {
            return -1;
        }

        return delay;
    }
};
