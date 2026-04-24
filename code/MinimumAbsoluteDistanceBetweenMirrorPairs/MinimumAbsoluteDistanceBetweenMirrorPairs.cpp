class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }

        return r;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};
