class Solution {
public:
    string removeStars(string s) {
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                idx--;
            } else {
                s[idx] = s[i];
                idx++;
            }
        }

        return s.substr(0, idx); // s[0:idx-1]
    }
};
