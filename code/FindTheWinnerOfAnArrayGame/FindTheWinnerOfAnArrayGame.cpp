class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max_num = arr[0];
        int wins = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (max_num < arr[i]) {
                max_num = arr[i];
                wins = 1;
            } else {
                wins++;
            }

            if (wins == k) {
                return max_num;
            }
        }

        return max_num;
    }
};
