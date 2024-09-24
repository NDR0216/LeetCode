const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }

        vector<pair<long long, int>> pq(nums.size());
        long long max_num = 0;

        for (int i = 0; i < nums.size(); i++) {
            pq[i] = {nums[i], i};
            max_num = max(max_num, (long long)nums[i]);
        }

        make_heap(pq.begin(), pq.end(), greater());

        // max value could be 1e9
        while (pq[0].first * multiplier <= max_num && k > 0) {
            pq[0].first *= multiplier;

            max_num = max(max_num, pq[0].first);

            pop_heap(pq.begin(), pq.end(), greater());
            push_heap(pq.begin(), pq.end(), greater());

            k--;
        }

        // every element *= multiplier^exp
        int exp = k / nums.size();
        k %= nums.size();

        long long pow = 1; // multiplier^exp
        long long base = multiplier;
        while (exp > 0) {
            if (exp % 2 == 1) {
                pow = (pow * base) % MOD;
            }

            base = (base * base) % MOD;

            exp /= 2;
        }

        // max value could be 1e15
        while (k > 0) {
            pq[0].first *= multiplier;

            pop_heap(pq.begin(), pq.end(), greater());
            push_heap(pq.begin(), pq.end(), greater());

            k--;
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[pq[i].second] = ((pq[i].first % MOD) * pow) % MOD;
        }

        return nums;
    }
};
