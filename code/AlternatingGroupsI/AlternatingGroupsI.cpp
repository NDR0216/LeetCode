class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int k = 3;
        int n = colors.size();

        int group = 0;

        int cnt = 1;
        // till [n-1, n+k-1)
        for (int i = 1; i < n + k - 1; i++) {
            if (colors[(i - 1) % n] != colors[i % n]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt >= k) {
                group++;
            }
        }

        return group;
    }
};
