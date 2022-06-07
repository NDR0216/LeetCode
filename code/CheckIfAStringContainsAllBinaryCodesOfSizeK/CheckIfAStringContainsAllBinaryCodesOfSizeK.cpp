class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<int, bool> dict;
        
        int key = 0;
        
        for (int i = 0; i < s.length(); i++) { // O(s.length)
            key = ((key*2) % (int) pow(2, k)) + s[i] - '0';
            
            if (i >= k-1) {
                dict[key] = true;
            }
        }
        
        for (int i = 0; i < pow(2, k); i++) { // O(2^k)
            if (dict.count(i) == 0) {
                return false;
            }
        }
        
        return true;
    }
};
