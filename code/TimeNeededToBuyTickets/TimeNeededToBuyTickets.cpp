class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                if (tickets[i] > tickets[k]) {
                    time += tickets[k];
                } else {
                    time += tickets[i];
                }
            } else { // after k
                if (tickets[i] > tickets[k] - 1) {
                    time += tickets[k] - 1;
                } else {
                    time += tickets[i];
                }
            }
        }

        return time;
    }
};
