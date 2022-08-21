class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int* cumm = new int[s.length()]{};
            
        for (int i = 0; i < shifts.size(); i++) {
            if (shifts[i][2] == 1) {
                cumm[shifts[i][0]] += 1;
                if (shifts[i][1]+1 < s.size()) {
                    cumm[shifts[i][1]+1] -= 1;
                }
            } else {
                cumm[shifts[i][0]] -= 1;
                if (shifts[i][1]+1 < s.size()) {
                    cumm[shifts[i][1]+1] += 1;
                }
            }
            
        }
        
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += cumm[i];
            
            int temp = s[i]-'a';
            
            temp += sum;
            
            while(temp < 0) {
                temp += 26;
            }
            while(temp >= 26) {
                temp -= 26;
            }
            
            s[i] = 'a'+temp;
        }
        
        return s;
    }
};
