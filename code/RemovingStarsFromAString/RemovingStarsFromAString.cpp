class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        int stars = 0; 
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == '*') {
                stars++;
                s[i] = ' ';
            } else {
                if (stars > 0) {
                    stars--;
                    s[i] = ' ';
                }
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                result += s[i];
            }
        }
        
        return result;
    }
};
