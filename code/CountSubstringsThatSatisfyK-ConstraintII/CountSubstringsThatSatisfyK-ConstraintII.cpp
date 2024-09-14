class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>>& queries) {
        vector<int> boundary(s.size(),
                             INT_MAX); // [i, boundary[i]] is invalid

        vector<long long> prefix_sum(s.size());

        int zeros = 0;
        int ones = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '0') {
                zeros++;
            } else {
                ones++;
            }

            while (left < s.size() && (zeros > k && ones > k)) {
                if (s[left] == '0') {
                    zeros--;
                } else {
                    ones--;
                }

                boundary[left] = right - 1;

                left++;
            }

            if (right == 0) {
                prefix_sum[right] = right - left + 1;
            } else {
                prefix_sum[right] = prefix_sum[right - 1] + right - left + 1;
            }
        }

        vector<long long> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l_i = queries[i][0];
            int r_i = queries[i][1];

            int mid = min(r_i, boundary[l_i]);

            // [mid, r_i] : prefix_sum[r_i] - prefix_sum[mid-1]
            // [l_i, mid-1] : (mid - l_i + 1) * (mid - l_i + 2) / 2

            answer[i] = prefix_sum[r_i] - prefix_sum[mid] +
                        (long long)(mid - l_i + 1) * (mid - l_i + 2) / 2;
        }

        return answer;
    }
};
