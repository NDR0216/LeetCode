class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        if (x < y) {
            swap(x, y);
        }

        if (x == 1 && y == 0) {
            return 3;
        }
        if (x == 2 && y == 2) {
            return 4;
        }

        int group;
        if (x - 2 * y > -4) {
            group = (x + 1) / 2;
        } else {
            group = (x + y + 1) / 3;
        }

        return group + (x + y + group) % 2;
    }
};
