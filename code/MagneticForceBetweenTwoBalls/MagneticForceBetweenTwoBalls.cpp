class Solution {
public:
    bool check(int dist, const vector<int>& position, int m) {
        int last = position[0];
        m--;

        for (int i = 0; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                last = position[i];
                m--;
            }

            if (m == 0) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        // binary search

        int left = INT_MAX; // min differnce
        for (int i = 1; i < position.size(); i++) {
            left = min(left, position[i] - position[i - 1] + 1);
        }
        int right = (position.back() - position[0]) / (m - 1) + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid, position, m)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left == right == first false, 1 element

        return left - 1; // return last true
    }
};
