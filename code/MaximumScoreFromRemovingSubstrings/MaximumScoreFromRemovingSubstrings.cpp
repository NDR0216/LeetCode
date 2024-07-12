class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (y > x) {
            reverse(s.begin(), s.end());
            return maximumGain(move(s), y, x);
        }

        int a = 0;
        int b = 0;

        int gain = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                a++;
            } else if (s[i] == 'b') {
                if (a > 0) {
                    a--;
                    gain += x;
                } else {
                    b++;
                }
            } else {
                gain += min(a, b) * y;
                a = 0;
                b = 0;
            }
        }

        return gain + min(a, b) * y;
    }
};
