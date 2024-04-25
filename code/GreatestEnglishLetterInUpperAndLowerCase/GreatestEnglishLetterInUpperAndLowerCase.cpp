class Solution {
public:
    string greatestLetter(string s) {
        map<char, int> dict;
        
        string letter = "";
        
        for (int i = 0; i < s.length(); i++){
            dict[s[i]] = 1;
            
            if (s[i] <= 'Z' && dict.count(s[i]+32) > 0) {
                if (letter == "") {
                    letter = s[i];
                } else if (letter[0] < s[i]) {
                    letter = s[i];
                }
            } else if (dict.count(s[i]-32) > 0) {
                if (letter == "") {
                    letter = s[i]-32;
                } else if (letter[0] < s[i]-32) {
                    letter = s[i]-32;
                }
            }
        }
        
        return letter;
    }
};
