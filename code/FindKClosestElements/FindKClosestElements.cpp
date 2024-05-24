class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left == right, 1 element

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = arr[left + i];
        }

        return result;
    }
};
