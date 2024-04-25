class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = logs[0][0];
        int max = logs[0][1];

        for (int i = 1; i < logs.size(); i++) {
            if (max < logs[i][1] - logs[i-1][1]) {
                max = logs[i][1] - logs[i-1][1];
                id = logs[i][0];
            } else if (max == logs[i][1] - logs[i-1][1] && id > logs[i][0]) {
                id = logs[i][0];
            }
        }
        
        return id;
    }
};
