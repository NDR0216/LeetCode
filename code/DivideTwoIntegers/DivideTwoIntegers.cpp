class Solution {
public:
    int divide(int dividend, int divisor) {
        long int dividend_;
        long int divisor_;
        long int quotient = 0;
        
        bool neg = false;
        
        dividend_ = dividend;
        if (dividend < 0) {
            dividend_ = 0 - dividend_;
            neg = !neg;
        }
        
        divisor_ = divisor;
        if (divisor < 0) {
            divisor_ = 0 - divisor_;
            neg = !neg;
        }
        
        for (int i = 31; i >= 0; i--) {
            quotient = quotient << 1;
            if (dividend_ - (divisor_ << i) >= 0) {
                quotient += 1;
                dividend_ -= (divisor_ << i);
            }
        }
        
        if (neg == true) {
            quotient = 0 - quotient;
        }
        
        if (quotient > pow(2,31)-1) {
            return pow(2,31)-1;
        } else if (quotient < -pow(2,31)) {
            return -pow(2,31);
        } else {
            return quotient;
        }
    }
};
