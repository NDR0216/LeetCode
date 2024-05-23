class Solution {
public:
    void DFS(int v, int n, bool* visited, const vector<vector<int>>& isConnected) {
        visited[v] = true;
        
        for (int i = 0; i < n; i++) {
            if (isConnected[v][i] == 1 && !visited[i]) {
                DFS(i, n, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        bool* visited = new bool[n]();

        int num = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, n, visited, isConnected);
                num++;
            }
        }

        return num;
    }
};
