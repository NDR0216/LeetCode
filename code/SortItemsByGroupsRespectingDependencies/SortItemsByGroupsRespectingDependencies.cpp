class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        // assign new group
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                group[i] = m;
                m++;
            }
        }

        vector<int>* group_idx = new vector<int>[m];
        for (int i = 0; i < n; i++) {
            group_idx[group[i]].push_back(i);
        }

        // Kahn
        vector<int>* graph_item = new vector<int>[n];
        vector<int>* graph_group = new vector<int>[m];
        int* indegree_item = new int[n]();
        int* indegree_group = new int[m]();

        for (int i = 0; i < beforeItems.size(); i++) {
            indegree_item[i] = beforeItems[i].size();

            for (int j = 0; j < beforeItems[i].size(); j++) {
                int a_i = beforeItems[i][j];
                int b_i = i;
                int group_a = group[a_i];
                int group_b = group[b_i];

                graph_item[a_i].push_back(b_i);

                if (group_a != group_b) {
                    graph_group[group_a].push_back(group_b);
                    indegree_group[group_b] += 1;
                }
            }
        }

        queue<int> indegree_0_group;
        for (int i = 0; i < m; i++) {
            if (indegree_group[i] == 0) {
                indegree_0_group.push(i);
            }
        }

        vector<int> order;

        // topo on group
        while (!indegree_0_group.empty()) {
            int group_id = indegree_0_group.front();
            indegree_0_group.pop();

            for (int i = 0; i < graph_group[group_id].size(); i++) {
                int u = graph_group[group_id][i];

                indegree_group[u] -= 1;

                if (indegree_group[u] == 0) {
                    indegree_0_group.push(u);
                }
            }

            // topo on item
            queue<int> indegree_0_item;
            for (int i = 0; i < group_idx[group_id].size(); i++) {
                int idx = group_idx[group_id][i];

                if (indegree_item[idx] == 0) {
                    indegree_0_item.push(idx);
                }
            }

            while (!indegree_0_item.empty()) {
                int v = indegree_0_item.front();
                indegree_0_item.pop();

                order.push_back(v);

                for (int i = 0; i < graph_item[v].size(); i++) {
                    int u = graph_item[v][i];

                    indegree_item[u] -= 1;

                    if (indegree_item[u] == 0 && group[u] == group_id) {
                        indegree_0_item.push(u);
                    }
                }
            }
        }

        if (order.size() != n) {
            order = {};
        }

        return order;
    }
};
