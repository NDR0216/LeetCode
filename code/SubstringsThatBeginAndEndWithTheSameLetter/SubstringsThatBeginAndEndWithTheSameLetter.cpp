class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, int> dict;
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]]++;
        }

        long long cnt = 0;
        for (unordered_map<char, int>::iterator it = dict.begin();
             it != dict.end(); ++it) {
            int value = it->second;

            cnt += (long long)value * (value + 1) / 2;
        }

        return cnt;
    }
};
