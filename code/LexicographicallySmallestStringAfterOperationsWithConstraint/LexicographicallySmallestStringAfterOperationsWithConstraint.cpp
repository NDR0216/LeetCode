class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); i++) {
            int dist_a = min(s[i] - 'a', 'z' + 1 - s[i]); // distance to 'a'
            if (dist_a <= k) { // can be changed to 'a'
                s[i] = 'a';
                k -= dist_a;
            } else {
                s[i] -= k;
                k = 0;
            }
        }

        return s;
    }
};
