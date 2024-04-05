class Solution {
public:
    string makeGood(string s) {
        stack<char> charStack;

        for (int i = 0; i < s.length(); i++) {
            if (!charStack.empty() && (charStack.top() == s[i] + 32 ||
                                       charStack.top() == s[i] - 32)) {
                charStack.pop();
            } else {
                charStack.push(s[i]);
            }
        }

        string output(charStack.size(), ' ');

        for (int i = charStack.size() - 1; i >= 0; i--) {
            output[i] = charStack.top();
            charStack.pop();
        }

        return output;
    }
};
