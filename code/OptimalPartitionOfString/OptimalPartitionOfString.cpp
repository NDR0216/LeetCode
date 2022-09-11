class Solution {
public:
    int partitionString(string s) {
        bool unique[26] = {false};    
        
        int num = 1;
        for (int i = 0; i < s.length(); i++) {           
            if (unique[s[i]-'a'] == false) {
                unique[s[i]-'a'] = true;
            } else {
                num++;
                for (int j = 0; j < 26; j++) {
                    unique[j] = false;
                }
                unique[s[i]-'a'] = true;
            }
        }
        
        return num;
    }
};
