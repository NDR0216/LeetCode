class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse()
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end) {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};
