class Solution {
public:
    string largestPalindrome(int n, int k) {
        switch (k) {
        case 1:
        case 3:
        case 9:
            return string(n, '9');
        case 2:
            if (n == 1) {
                return "8";
            }
            return "8" + string(n - 2, '9') + "8";
        case 4:
            if (n < 4) {
                return string(n, '8');
            }
            return "88" + string(n - 4, '9') + "88";
        case 5:
            if (n == 1) {
                return "5";
            }
            return "5" + string(n - 2, '9') + "5";
        case 8:
            if (n < 6) {
                return string(n, '8');
            }
            return "888" + string(n - 6, '9') + "888";
        case 6:
            if (n < 3) {
                return string(n, '6');
            }
            if (n % 2 == 1) {
                return "8" + string((n - 3) / 2, '9') + "8" +
                       string((n - 3) / 2, '9') + "8";
            } else {
                return "8" + string((n - 4) / 2, '9') + "77" +
                       string((n - 4) / 2, '9') + "8";
            }
        case 7:
            switch (n % 12) {
            case 0:
            case 6:
                return string(n, '9');
            case 1:
            case 5:
                return string((n - 1) / 2, '9') + "7" +
                       string((n - 1) / 2, '9');
            case 2:
            case 4:
                return string((n - 2) / 2, '9') + "77" +
                       string((n - 2) / 2, '9');
            case 3:
                return string((n - 1) / 2, '9') + "5" +
                       string((n - 1) / 2, '9');
            case 7:
            case 11:
                return string((n - 1) / 2, '9') + "4" +
                       string((n - 1) / 2, '9');
            case 8:
            case 10:
                return string((n - 2) / 2, '9') + "44" +
                       string((n - 2) / 2, '9');
            case 9:
                return string((n - 1) / 2, '9') + "6" +
                       string((n - 1) / 2, '9');
            }
        }

        return "";
    }
};
