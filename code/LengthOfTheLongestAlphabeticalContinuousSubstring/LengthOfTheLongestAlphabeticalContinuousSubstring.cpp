class Solution {
public:
    int longestContinuousSubstring(string s) {
        int max = 0;
        int length = 0;
        char first_char = 'a';
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == first_char+length) {
                length++;
            } else {
                length = 1;
                first_char = s[i];
            }
            
            if (length > max) {
                max = length;
            }
        }
        
        return max;
    }
};
