class Solution {
public:
    bool topo_DFS(int v, vector<bool>* visited, vector<bool>* curr_visited,
                  vector<int>* order, vector<int>* graph) {
        (*visited)[v] = true;
        (*curr_visited)[v] = true;

        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];

            if ((*curr_visited)[u]) {
                return false;
            }

            if (!(*visited)[u]) {
                if (!topo_DFS(u, visited, curr_visited, order, graph)) {
                    return false;
                }
            }
        }

        (*curr_visited)[v] = false;

        order->push_back(v);

        return true;
    }

    vector<int> topo(int n, vector<int>* graph) {
        vector<bool> visited(n);
        vector<bool> curr_visited(n);
        vector<int> order;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!topo_DFS(i, &visited, &curr_visited, &order, graph)) {
                    return {};
                }
            }
        }

        return order;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* graph = new vector<int>[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            int a_i = prerequisites[i][0];
            int b_i = prerequisites[i][1];

            graph[a_i].push_back(b_i);
        }

        return topo(numCourses, graph);
    }
};
