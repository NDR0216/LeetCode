class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - k < 'a' || s[i] + k > 'z') {
                k -= min('z' + 1 - s[i], s[i] - 'a');
                s[i] = 'a';
            } else {
                s[i] -= k;
                k = 0;
            }
        }

        return s;
    }
};
