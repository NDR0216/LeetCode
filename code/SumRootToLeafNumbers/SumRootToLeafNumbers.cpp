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
    int sumNumbers_(TreeNode* root, int num) {
        if (!root) {
            return 0;
        }

        num = 10 * num + root->val;

        if (!root->left && !root->right) { // leaf node
            return num;
        }

        return sumNumbers_(root->left, num) + sumNumbers_(root->right, num);
    }

    int sumNumbers(TreeNode* root) { return sumNumbers_(root, 0); }
};
