class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0;
        int idle = 0;

        for (int i = 0; i < customers.size(); i++) {
            int arrival_i = customers[i][0];
            int time_i = customers[i][1];

            idle = max(idle, arrival_i) + time_i;
            total += last - arrival_i;
        }

        return total / customers.size();
    }
};
