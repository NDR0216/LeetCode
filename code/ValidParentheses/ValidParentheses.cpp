class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bracket.push(s[i]);
            } else {
                if (bracket.empty() || (s[i] == ')' && bracket.top() != '(') ||
                    (s[i] == '}' && bracket.top() != '{') ||
                    (s[i] == ']' && bracket.top() != '[')) {
                    return false;
                }

                bracket.pop();
            }
        }

        return bracket.empty();
    }
};
