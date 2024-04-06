class Solution {
public:
    string makeGood(string s) {
        string output;

        for (int i = 0; i < s.length(); i++) {
            if (!output.empty() &&
                (output.back() == s[i] + 32 || output.back() == s[i] - 32)) {
                output.pop_back();
            } else {
                output.push_back(s[i]);
            }
        }

        return output;
    }
};
