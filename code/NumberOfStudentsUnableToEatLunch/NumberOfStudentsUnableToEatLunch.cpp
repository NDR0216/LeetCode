class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int students_0 = 0;
        int students_1 = 0;

        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                students_0++;
            } else {
                students_1++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (students_0 > 0) {
                    students_0--;
                } else {
                    return students_1;
                }
            } else {
                if (students_1 > 0) {
                    students_1--;
                } else {
                    return students_0;
                }
            }
        }

        return 0;
    }
};
