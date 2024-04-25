class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[1] == suits[0] && suits[2] == suits[0] && suits[3] == suits[0] && suits[4] == suits[0]) {
            return "Flush";
        }
        
        map<int, int> dict_rank;
        for (int i = 1; i < 13; i++) {
            dict_rank[i] = 0;
        }

        int max = 0;
        for (int i = 0; i < 5; i++) {
            dict_rank[ranks[i]] += 1;
            
            if (dict_rank[ranks[i]] > max) {
                max = dict_rank[ranks[i]];
            }
        }
        
        if (max >= 3) {
            return "Three of a Kind";
        } else if (max == 2) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
};
