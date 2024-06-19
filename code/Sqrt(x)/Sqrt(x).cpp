class Solution {
private:
    const int MAX_VALUE = 46340;

public:
    int mySqrt(int x) {
        int left = 0, right = min(x, MAX_VALUE);
        while (left <= right) {
            int mid = (left + right) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // right*right < x < left*left, 0 element

        return right;
    }
};
