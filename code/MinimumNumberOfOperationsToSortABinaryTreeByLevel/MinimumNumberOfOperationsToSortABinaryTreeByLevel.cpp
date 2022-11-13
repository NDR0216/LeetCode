/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool comp (int i,int j) { 
        return (i<j); 
    }
    
    
    int minimumOperations(TreeNode* root) {
        int operations = 0;

        vector<TreeNode*> level;
        vector<TreeNode*> next_level;
                
        vector<int> list;
        
        level.push_back(root);
        
        while (!level.empty()) {
            next_level.clear();
            list.clear();
            for (int i = 0; i < level.size(); i++) {
                TreeNode* node = level[i];
                if (node->left != NULL) {
                    next_level.push_back(node->left);
                    list.push_back(node->left->val);
                }
                if (node->right != NULL) {
                    next_level.push_back(node->right);
                    list.push_back(node->right->val);
                }
            }
            level = next_level;
            
            vector<int> list_sort(list);
            sort(list_sort.begin(), list_sort.end());
            
            map<int, int> dict;
            for (int i = 0; i < list.size(); i++) {
                dict[list_sort[i]] = i;
            }
            
            vector<int> edge(list.size());
            for (int i = 0; i < list.size(); i++) {
                edge[i] = dict[list[i]];
            }
            
            vector<bool> visited(list.size(), false);
            int cycle = 0;
            for (int i = 0; i < list.size(); i++) {
                if (!visited[i]) {
                    int idx = i;
                    while (!visited[idx]) {
                        visited[idx] = true;
                        idx = edge[idx];
                    }
                    
                    cycle++;
                }
            }
            operations += list.size()-cycle;
        }
        
        return operations;
    }
};
