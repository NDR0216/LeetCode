class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool between = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                between = !between;
            } else if (between == false && s[i] == '*') {
                cnt++;
            }
        }
        
        return cnt;
    }
};
