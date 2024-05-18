class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        vector<int>* graph = new vector<int>[n];
        int* indegree = new int[n]();
        int* indegree_group = new int[m]();

        for (int i = 0; i < beforeItems.size(); i++) {
            indegree[i] = beforeItems[i].size();

            for (int j = 0; j < beforeItems[i].size(); j++) {
                int a_i = beforeItems[i][j];
                int b_i = i;
                int group_a = group[a_i];
                int group_b = group[b_i];

                graph[a_i].push_back(b_i);

                if (group_b != -1 && group_a != group_b) {
                    indegree_group[group_b] += 1;
                }
            }
        }

        vector<vector<int>> group_(m, vector<int>());
        for (int i = 0; i < n; i++) {
            if (group[i] != -1) {
                group_[group[i]].push_back(i);
            }
        }

        queue<pair<bool, int>> indegree_0;
        for (int i = 0; i < m; i++) {
            if (indegree_group[i] == 0) {
                indegree_0.push({true, i});
            }
        }
        for (int i = 0; i < n; i++) {
            int group_id = group[i];

            if (group_id == -1 && indegree[i] == 0) {
                indegree_0.push({false, i});
            }
        }

        vector<int> order;

        while (!indegree_0.empty()) {
            pair<bool, int> p = indegree_0.front();
            indegree_0.pop();

            if (!p.first) { // group_id == -1
                int v = p.second;

                order.push_back(v);

                for (int i = 0; i < graph[v].size(); i++) {
                    int u = graph[v][i];
                    int group_id = group[u];

                    indegree[u] -= 1;
                    if (group_id != -1) {
                        indegree_group[group_id] -= 1;
                    }

                    if (group_id == -1 && indegree[u] == 0) {
                        indegree_0.push({false, u});
                    } else if (group_id != -1 &&
                               indegree_group[group_id] == 0) {
                        indegree_0.push({true, group_id});
                    }
                }
            } else {
                int group_id = p.second;

                queue<int> curr_group;

                for (int i = 0; i < group_[group_id].size(); i++) {
                    int idx = group_[group_id][i];

                    if (indegree[idx] == 0) {
                        curr_group.push(idx);
                    }
                }

                while (!curr_group.empty()) {
                    int vv = curr_group.front();
                    curr_group.pop();

                    order.push_back(vv);

                    for (int i = 0; i < graph[vv].size(); i++) {
                        int u = graph[vv][i];

                        indegree[u] -= 1;
                        if (group[u] != -1 && group[u] != group_id) {
                            indegree_group[group[u]] -= 1;
                        }

                        if (indegree[u] == 0 && group[u] == group_id) {
                            curr_group.push(u);
                        } else if (group[u] == -1 && indegree[u] == 0) {
                            indegree_0.push({false, u});
                        } else if (group[u] != -1 && group[u] != group_id &&
                                   indegree_group[group[u]] == 0) {
                            indegree_0.push({true, group[u]});
                        }
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
