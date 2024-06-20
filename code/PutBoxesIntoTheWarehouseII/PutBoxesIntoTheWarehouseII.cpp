class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater());

        // one pass

        int max_box = 0;
        int idx = 0;

        int left = 0;
        int right = warehouse.size() - 1;
        while (left <= right && idx < boxes.size()) {
            if (boxes[idx] <= warehouse[left]) {
                max_box++;
                left++;
            } else if (boxes[idx] <= warehouse[right]) {
                max_box++;
                right--;
            }

            idx++;
        }

        return max_box;
    }
};
