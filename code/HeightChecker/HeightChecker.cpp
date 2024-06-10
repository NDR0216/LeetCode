// the two children of idx are heaps, idx isn't
template <typename Iter> void heapify(Iter begin, Iter end, int idx) {
    int len = end - begin;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int max_idx = idx;
    if ((left < len) && *(begin + left) > *(begin + max_idx)) {
        max_idx = left;
    }
    if ((right < len) && *(begin + right) > *(begin + max_idx)) {
        max_idx = right;
    }

    if (max_idx != idx) {
        swap(*(begin + max_idx), *(begin + idx));
        heapify(begin, end, max_idx);
    }
}

template <typename Iter> void heapsort(Iter begin, Iter end) {
    int len = end - begin;
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(begin, end, i);
    }

    while (begin != end) {
        --end;
        swap(*begin, *end);
        heapify(begin, end, 0);
    }
}

template <typename Iter> void mergesort(Iter begin, Iter end) {
    int len = end - begin;
    if (len <= 1) { // 1 element
        return;
    }

    Iter mid = begin + len / 2;
    mergesort(begin, mid); // [begin, mid-1]
    mergesort(mid, end);   // [mid, end)

    // merge
    Iter it1 = begin;
    Iter it2 = mid;
    typename Iter::value_type* copy = new Iter::value_type[len];
    for (int i = 0; i < len; i++) {
        if (it1 != mid && (it2 == end || *it1 < *it2)) {
            copy[i] = *it1;
            ++it1;
        } else {
            copy[i] = *it2;
            ++it2;
        }
    }
    swap_ranges(begin, end, copy);
}

template <typename Iter> void quicksort(Iter begin, Iter end) {
    int len = end - begin;
    if (len <= 1) { // 1 element
        return;
    }

    // partition
    Iter pivot = begin; // the idx which pivot will be
    for (Iter it = begin; it != end - 1; ++it) {
        if (*it < *(end - 1)) {
            swap(*pivot, *it);
            ++pivot;
        }
    }
    swap(*pivot, *(end - 1));

    quicksort(begin, pivot);   // [begin, pivot-1]
    quicksort(pivot + 1, end); // [mid, end)
}

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy(heights);
        sort(copy.begin(), copy.end());
        // heapsort(copy.begin(), copy.end());
        // mergesort(copy.begin(), copy.end());
        // quicksort(copy.begin(), copy.end());

        int cnt = 0;
        for (int i = 0; i < heights.size(); i++) {
            cnt += heights[i] != copy[i];
        }

        return cnt;
    }
};
