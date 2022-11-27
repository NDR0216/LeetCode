class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (idx < t.length() && s[i] == t[idx]) {
                idx++;
            }
        }
        
        return t.length()-idx;
    }
};
