/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves_(TreeNode* root, bool left) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            if (left) {
                return root->val;
            } else {
                return 0;
            }
        }

        return sumOfLeftLeaves_(root->left, true) +
               sumOfLeftLeaves_(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves_(root, false);
    }
};
