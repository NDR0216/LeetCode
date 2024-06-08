class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> freq;

        // max_length = left - right
        int right = 0;
        int left = 0;
        for (right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            if (freq.size() > 2) {
                freq[s[left]] -= 1;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }
        }

        return right - left;
    }
};
