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
    int sumOfLeftLeaves_(TreeNode* root, bool left) {
        if (!root->left && !root->right) {
            if (left) {
                return root->val;
            } else {
                return 0;
            }
        }

        int sum = 0;
        if (root->left) {
            sum += sumOfLeftLeaves_(root->left, true);
        }

        if (root->right) {
            sum += sumOfLeftLeaves_(root->right, false);
        }

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves_(root, false);
    }
};
