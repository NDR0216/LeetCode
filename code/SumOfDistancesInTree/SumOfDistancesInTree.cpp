class Solution {
public:
    // first DFS, calculate answer[0] and fill the cnt array
    int DFS1(int root, int parent, vector<int>* graph, vector<int>* cnt) {
        int sum = 0;

        for (int i = 0; i < graph[root].size(); i++) {
            int child = graph[root][i];

            if (child != parent) {
                sum += DFS1(child, root, graph, cnt) + (*cnt)[child];

                (*cnt)[root] += (*cnt)[child];
            }
        }

        return sum;
    }

    // second DFS, calculate the answer
    void DFS2(int root, int parent, int n, vector<int>* graph,
              const vector<int>& cnt, vector<int>* answer) {
        for (int i = 0; i < graph[root].size(); i++) {
            int child = graph[root][i];

            if (child != parent) {
                (*answer)[child] =
                    (*answer)[root] - cnt[child] + (n - cnt[child]);

                DFS2(child, root, n, graph, cnt, answer);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // adjacency list
        vector<int>* graph = new vector<int>[n];
        for (int i = 0; i < edges.size(); i++) {
            int u_i = edges[i][0];
            int v_i = edges[i][1];

            graph[u_i].push_back(v_i);
            graph[v_i].push_back(u_i);
        }

        vector<int> cnt(n, 1); // nodes in subtree
        vector<int> answer(n);

        // first DFS, calculate answer[0] and fill the cnt array
        answer[0] = DFS1(0, -1, graph, &cnt);

        // second DFS, calculate the answer
        DFS2(0, -1, n, graph, cnt, &answer);

        return answer;
    }
};
