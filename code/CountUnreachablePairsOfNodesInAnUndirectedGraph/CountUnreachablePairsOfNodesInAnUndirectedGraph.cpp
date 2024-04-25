class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long num = 0;
        
        vector<vector<int>> in_list(n, vector<int> (0));
        vector<vector<int>> out_list(n, vector<int> (0));
        
        for (int i = 0; i < edges.size(); i++) {
            in_list[edges[i][0]].push_back(edges[i][1]);
            out_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        bool* visited = new bool[n];
        
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        
        stack<int> node_stack;
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                long long temp = 0;
                visited[i] = true;
                temp++;
                node_stack.push(i);
                
                while (!node_stack.empty()) {
                    int node = node_stack.top();
                    node_stack.pop();
                    for (int j = 0; j < in_list[node].size(); j++) {
                        if (visited[in_list[node][j]] == false) {
                            visited[in_list[node][j]] = true;
                            temp++;
                            node_stack.push(in_list[node][j]);
                        }
                    }
                    for (int j = 0; j < out_list[node].size(); j++) {
                        if (visited[out_list[node][j]] == false) {
                            visited[out_list[node][j]] = true;
                            temp++;
                            node_stack.push(out_list[node][j]);
                        }
                    }
                }
                
                num += temp*(n-temp);
            }
        }
        
        return num/2;
    }
};
