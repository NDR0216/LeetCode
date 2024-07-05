class Solution {
private:
    const int ODD = 3;

public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2) {
                odd++;
                if (odd == ODD) {
                    return true;
                }
            } else {
                odd = 0;
            }
        }

        return false;
    }
};
