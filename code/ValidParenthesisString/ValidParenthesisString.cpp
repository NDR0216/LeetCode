class Solution {
public:
    bool checkValidString(string s) {
        int max_paren = 0; // max of possible '('
        int min_paren = 0; // min of possible '('

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                max_paren++;
                min_paren++;
            } else if (s[i] == ')') {
                if (max_paren == 0) { // '(' not enough
                    return false;
                } else {
                    max_paren--;
                    min_paren = max(0, min_paren - 1);
                }
            } else { // s[i] == '*'
                max_paren++;
                min_paren = max(0, min_paren - 1);
            }
        }

        return (min_paren <= 0); // min_paren > 0: too many '('
    }
};
