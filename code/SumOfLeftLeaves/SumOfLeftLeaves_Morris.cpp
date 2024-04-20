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
    int sumOfLeftLeaves(TreeNode* root) {
        // Morris

        // if predecessor->right == NULL, predecessor->right = root, and visit
        // root->left
        // else, revert the change, visit root, and visit root->right

        int sum = 0;

        // the right children of the last visited node will be NULL
        while (root) {
            if (!root->left) {
                root = root->right; // visit root->right, could be successor or
                                    // right subtree or NULL
            } else {
                if (!root->left->left &&
                    !root->left->right) { // when left_leaf->right != root
                    sum += root->left->val;
                }

                // find the predecessor
                TreeNode* predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    predecessor->right = root;

                    root = root->left; // visit root->left
                } else { // predecessor->right == root. which means left subtree
                         // have been visited
                    predecessor->right = NULL; // revert the change
                    root = root->right;        // visit root->right
                }
            }
        }

        return sum;
    }
};
