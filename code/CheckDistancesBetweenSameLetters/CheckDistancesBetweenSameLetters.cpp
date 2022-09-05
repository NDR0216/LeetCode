class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int idx[26]{};
        
        for (int i = 0; i < s.length(); i++) {
            if (idx[s[i]-'a'] == 0) {
                idx[s[i]-'a'] = i + distance[s[i]-'a'] + 1;
                
            } else if (i != idx[s[i]-'a']) {
                return false;
            }
        }
        
        return true;
    }
};
