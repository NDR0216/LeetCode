class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int paren_cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                paren_cnt++;
            } else if (s[i] == ')') {
                if (paren_cnt == 0) {
                    s[i] = '\0';
                    continue;
                }
                paren_cnt--;
            }
        }

        paren_cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                paren_cnt++;
            } else if (s[i] == '(') {
                if (paren_cnt == 0) {
                    s[i] = '\0';
                    continue;
                }
                paren_cnt--;
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
