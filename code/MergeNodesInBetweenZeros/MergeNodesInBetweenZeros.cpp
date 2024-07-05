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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modified = head;
        ListNode* p = head;

        p = p->next;
        while (p->next) { // when not at the end of the linked list
            if (p->val == 0) {
                modified = modified->next;
                modified->val = 0;
            } else {
                modified->val += p->val;
            }

            p = p->next;
        }

        modified->next = nullptr;

        return head;
    }
};
