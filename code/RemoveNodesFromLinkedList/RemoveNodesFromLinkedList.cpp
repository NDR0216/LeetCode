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
    ListNode* removeNodes(ListNode* head) {
        ListNode* root;
        
        vector<int> list;
        
        ListNode* node = head;
        while (node != NULL) {
            list.push_back(node->val);
            
            node = node->next;
        }
        
        vector<int> list_modified;
        int val_prev = list[list.size()-1];
        for (int i = list.size()-1; i >= 0; i--) {
            if (list[i] >= val_prev) {
                list_modified.push_back(list[i]);
                val_prev = list[i];
            }
        }
        
        root = new ListNode(list_modified[list_modified.size()-1]);
        
        node = root;
        for (int i = list_modified.size()-2; i >= 0; i--) {
            ListNode* temp = new ListNode(list_modified[i]);
            
            node->next = temp;
            node = temp;
        }
        
        return root;
    }
};
