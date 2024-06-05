class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        int length = 0;
        bool odd = false;
        for (unordered_map<char, int>::iterator it = freq.begin();
             it != freq.end(); ++it) {
            int value = it->second;

            length += value - value % 2;
            odd |= value % 2;
        }

        return length + odd;
    }
};
