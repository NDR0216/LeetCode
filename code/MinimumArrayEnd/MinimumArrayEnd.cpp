class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> answer(x);
        bitset<64> n_bin(n - 1);

        int idx = 0;
        for (int i = 0; i < 64; i++) {
            if (!answer[i]) {
                answer[i] = n_bin[idx];
                idx++;
            }
        }

        return answer.to_ullong();
    }
};
