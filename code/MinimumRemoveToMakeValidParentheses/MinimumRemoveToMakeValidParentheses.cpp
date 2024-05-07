class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // two pass
        int cnt_paren = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt_paren++;
            } else if (s[i] == ')') {
                if (cnt_paren == 0) {
                    s[i] = '\0';
                } else {
                    cnt_paren--;
                }
            }
        }

        cnt_paren = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                cnt_paren++;
            } else if (s[i] == '(') {
                if (cnt_paren == 0) {
                    s[i] = '\0';
                } else {
                    cnt_paren--;
                }   
            }
        }

        string output;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '\0') {
                output.push_back(s[i]);
            }
        }

        return output;
    }
};
