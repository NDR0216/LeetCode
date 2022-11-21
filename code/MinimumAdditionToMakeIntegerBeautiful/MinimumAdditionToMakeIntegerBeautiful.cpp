class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {   
        int digit[13];
        
        long long temp = n;
        for (int i = 12; i >= 0; i--) {
            digit[i] = temp / pow(10, i);
            temp -= digit[i] * pow(10, i);
        }
        
        int sum = 0;
        for (int i = 12; i >= 0; i--) {
            sum += digit[i];
            
            if (sum > target) {
                while (sum > target) {
                    sum = sum - digit[i] + 1;

                    digit[i] = 0;
                    digit[i+1] += 1;
                    i++;
                }
                i--;
                while (i >= 0) {
                    digit[i] = 0;
                    i--;
                }
                break;
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < 13; i++) {
            ans += digit[i] * pow(10, i);
        }
        
        return ans-n;
    }
};
