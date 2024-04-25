class Solution {
public:
    int fillCups(vector<int>& amount) {
        int num = 0;
        while (amount[0] != 0 || amount[1] != 0 || amount[2] != 0) {
            if (amount[0] >= amount[2] && amount[1] >= amount[2]) {
                if (amount[0] == 0 || amount[1] == 0) {
                    num += amount[0] + amount[1];
                    amount[0] = 0;
                    amount[1] = 0;
                } else {
                    amount[0]--;
                    amount[1]--;
                    num++;
                }
                
                
            } else if (amount[0] >= amount[1] && amount[2] >= amount[1]) {
                if (amount[0] == 0 || amount[2] == 0) {
                    num += amount[0] + amount[2];
                    amount[0] = 0;
                    amount[2] = 0;
                } else {
                    amount[0]--;
                    amount[2]--;
                    num++;
                }
            } else {
                if (amount[1] == 0 || amount[2] == 0) {
                    num += amount[1] + amount[2];
                    amount[1] = 0;
                    amount[2] = 0;
                } else {
                    amount[1]--;
                    amount[2]--;
                    num++;
                }
            }

        }
        
        return num;
    }
};
