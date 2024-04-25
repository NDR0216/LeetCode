class Solution {
public:
    int minimumNumbers(int num, int k) {
        int size = 0;
        
        if (num == 0) {
            return 0;
        }
        
        if (k == 0) {
            if (num % 10 == 0) {
                return 1;
            }
            return -1;
        }
        
        while (num > 0) {
            num -= k;
            size++;
            if (num % 10 == 0) {
                return size;
            }
        }
        
        return -1;
    }
};
