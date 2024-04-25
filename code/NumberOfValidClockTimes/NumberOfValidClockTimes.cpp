class Solution {
public:
    int countTime(string time) {
        int cnt = 1;
        if (time[0] == '?'&& time[1] == '?') {
            cnt *= 24;
        } else if (time[0] == '?') {
            if (time[1] < '4') {
                cnt *= 3;
            } else {
                cnt *= 2;
            }
        } else if (time[1] == '?') {
            if (time[0] < '2') {
                cnt *= 10;
            } else {
                cnt *= 4;
            }
        }
        if (time[3] == '?') {
            cnt *= 6;
        }
        if (time[4] == '?') {
            cnt *= 10;
        }
        
        return cnt;
    }
};
