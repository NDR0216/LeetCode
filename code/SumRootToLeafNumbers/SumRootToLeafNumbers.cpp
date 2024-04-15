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
        if (!root->left && !root->right) {
            return 10 * num + root->val;
        }

        int sum = 0;
        if (root->left) {
            sum += sumNumbers_(root->left, 10 * num + root->val);
        }
        if (root->right) {
            sum += sumNumbers_(root->right, 10 * num + root->val);
        }

        return sum;
    }

    int sumNumbers(TreeNode* root) { return sumNumbers_(root, 0); }
};
