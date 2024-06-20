class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater());

        // one pass

        int max_box = 0;
        int idx = 0;
        for (int i = 0; i < warehouse.size(); i++) {
            while (idx < boxes.size() && boxes[idx] > warehouse[i]) {
                idx++;
            }

            if (idx == boxes.size()) {
                return max_box;
            }

            max_box++;
            idx++;
        }

        return max_box;
    }
};
