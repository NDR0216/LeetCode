class Solution {
public:
    string removeKdigits(string num, int k) {
        string mono_stack;

        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !mono_stack.empty() && mono_stack.back() > num[i]) {
                mono_stack.pop_back();
                k--;
            }

            if (!mono_stack.empty() || num[i] != '0') {
                mono_stack.push_back(num[i]);
            }
        }

        // if k > 0
        for (int i = 0; !mono_stack.empty() && i < k; i++) {
            mono_stack.pop_back();
        }

        if (mono_stack.empty()) {
            return "0";
        }

        return mono_stack;
    }
};
