class Solution {
public:
    bool checkValidString(string s) {
        int paren_cnt_max = 0; // max of possible '('
        int paren_cnt_min = 0; // min of possible '('

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                paren_cnt_max++;
                paren_cnt_min++;
            } else if (s[i] == ')') {
                if (paren_cnt_max == 0) { // '(' not enough
                    return false;
                } else {
                    paren_cnt_max--;
                    paren_cnt_min--;
                }

                if (paren_cnt_min < 0) {
                    paren_cnt_min = 0;
                }
            } else if (s[i] == '*') {
                paren_cnt_max++;
                paren_cnt_min--;

                if (paren_cnt_min < 0) {
                    paren_cnt_min = 0;
                }
            }
        }

        return (paren_cnt_min <= 0); // paren_cnt_min > 0: too many '('
    }
};
