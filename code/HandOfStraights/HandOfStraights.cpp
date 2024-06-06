class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> freq;
        for (int i = 0; i < hand.size(); i++) {
            freq[hand[i]]++;
        }

        for (int i = 0; i < hand.size(); i++) {
            int start = hand[i];
            
            while (freq[start - 1] != 0) {
                start--;
            }

            while (start <= hand[i]) {
                int count = freq[start];

                if (count != 0) {
                    for (int i = 0; i < groupSize; i++) {
                        if (freq[start + i] < count) {
                            return false;
                        }

                        freq[start + i] -= count;
                    }
                }

                start++;
            }
        }

        return true;
    }
};
