class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int max_idx = 0;
        int wins = 0;
        
        for (int i = 1; i < skills.size(); i++) {
            if (skills[max_idx] < skills[i]) {
                max_idx = i;
                wins = 1;
            } else {
                wins++;
            }

            if (wins == k) {
                return max_idx;
            }
        }

        return max_idx;
    }
};
