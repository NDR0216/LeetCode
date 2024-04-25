class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        
        for (int i = 0; i < brackets.size(); i++) {
            if (income > brackets[i][0]) {
                if (i > 0) {
                    tax += (brackets[i][0]-brackets[i-1][0]) * brackets[i][1] * 0.01;
                } else {
                    tax += brackets[i][0] * brackets[i][1] * 0.01;
                }     
            } else {
                if (i > 0) {
                    tax += (income-brackets[i-1][0]) * brackets[i][1] * 0.01;
                } else {
                    tax += income * brackets[i][1] * 0.01;
                }
                break;
            }
        }
        
        return tax;
    }
};
