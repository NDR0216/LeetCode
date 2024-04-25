class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set_bits = 0;
        
        while (num2 != 0) {
            if (num2 % 2 == 1) {
                set_bits++;
            }
            num2 = num2 >> 1;
        }
        
        int x = 0;
        for (int i = 31; i >= 0; i--) {
            x = x << 1;
            if (num1 / (1 << i) > 0 && set_bits > 0) {
                num1 -= (1 << i);
                set_bits--;
                x += 1;
            } else if (set_bits > i && set_bits > 0) {
                set_bits--;
                x += 1;                
            }
        }
        
        return x;
    }
};
