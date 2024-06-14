class Solution {
public:
    string clearDigits(string s) {
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                idx--;
            } else {
                s[idx] = s[i];
                idx++;
            }
        }

        return s.substr(0, idx); // s[0:idx-1]
    }
};
