class Solution {
public:
    bool DFS(int v, vector<bool>* visited, vector<bool>* curr_visited,
             vector<int>* graph) {
        (*visited)[v] = true;
        (*curr_visited)[v] = true;

        for (int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];

            if ((*curr_visited)[u]) {
                return false;
            }

            if (!(*visited)[u]) {
                if (!DFS(u, visited, curr_visited, graph)) {
                    return false;
                }
            }
        }

        (*curr_visited)[v] = false;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* graph = new vector<int>[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            int a_i = prerequisites[i][0];
            int b_i = prerequisites[i][1];

            graph[a_i].push_back(b_i);
        }

        vector<bool> visited(numCourses);
        vector<bool> curr_visited(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!DFS(i, &visited, &curr_visited, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};
