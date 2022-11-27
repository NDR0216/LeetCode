class Solution {
public:
    int pivotInteger(int n) {
        int total = n*(n+1)/2;
        
        int sum = 0;
        for (int j = n; j >= 0; j--){
            sum += j;
            if (sum*2-j == total) {
                return j;
            }
        }
        
        return -1;
    }
};
