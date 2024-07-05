/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_crit = -1;
        int last_crit = -1;

        int minDistance = INT_MAX;

        int idx = 0;
        while (head->next->next) {
            // head is previous
            ListNode* currNode = head->next;
            ListNode* nextNode = head->next->next;

            if ((currNode->val > head->val && currNode->val > nextNode->val) ||
                (currNode->val < head->val && currNode->val < nextNode->val)) {

                if (first_crit == -1) {
                    first_crit = idx;
                } else {
                    minDistance = min(minDistance, idx - last_crit);
                }

                last_crit = idx;
            }

            idx++;
            head = head->next;
        }

        if (last_crit == first_crit) {
            return {-1, -1};
        }

        return {minDistance, last_crit - first_crit};
    }
};
