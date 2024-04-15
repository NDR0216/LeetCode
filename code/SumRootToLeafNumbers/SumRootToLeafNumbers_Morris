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
    int sumNumbers(TreeNode* root) {
        // Morris

        // if predecessor->right == NULL, predecessor->right = root, and visit
        // root->left
        // else, revert the change, visit root, and visit root->right

        int sum = 0;
        int current_sum = 0;

        // the right children of the last visited node will be NULL
        while (root) {
            if (!root->left) {
                current_sum = 10 * current_sum + root->val;

                if (!root->right) { // the last visited node
                    sum += current_sum;
                }

                root = root->right; // visit root->right, could be successor or
                                    // right subtree or NULL
            } else {
                // find the predecessor
                TreeNode* predecessor = root->left;
                int level = 1;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                    level++;
                }

                if (!predecessor->right) {
                    predecessor->right = root;

                    current_sum = 10 * current_sum + root->val;
                    root = root->left; // visit root->left
                } else { // predecessor->right == root, which means left subtree
                         // have been visited
                    predecessor->right = NULL; // revert the change

                    if (!predecessor->left) { // if predecessor is a leaf
                        sum += current_sum;   // add the sum of the predecessor
                    }

                    current_sum /= pow(10, level); // calculate the correct sum
                    root = root->right;            // visit root->right
                }
            }
        }

        return sum;
    }
};
