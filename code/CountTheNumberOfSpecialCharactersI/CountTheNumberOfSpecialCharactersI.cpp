class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool uppercase[26] = {};
        bool lowercase[26] = {};

        for (int i = 0; i < word.size(); i++) {
            if (word[i] <= 'Z') {
                uppercase[word[i] - 'A'] = true;
            } else {
                lowercase[word[i] - 'a'] = true;
            }
        }

        int special = 0;
        for (int i = 0; i < 26; i++) {
            if (uppercase[i] && lowercase[i]) {
                special++;
            }
        }

        return special;
    }
};
