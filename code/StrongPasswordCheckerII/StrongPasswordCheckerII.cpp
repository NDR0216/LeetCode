class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool special = false;
        
        if (password.size() < 8) {
            return false;
        }
        
        for (int i = 0; i < password.size(); i++) {
            if (password[i] >= 'a' && password[i] <= 'z') {
                lowercase = true;
            } else if (password[i] >= 'A' && password[i] <= 'Z') {
                uppercase = true;
            } else if (password[i] >= '0' && password[i] <= '9') {
                digit = true;
            } else if (password[i] != '!' || password[i] != '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+') {
                special = true;
            }

            if (i > 0 && password[i] == password[i-1]) {
                return false;
            }
        }
        return lowercase && uppercase && digit && special;
    }
};
