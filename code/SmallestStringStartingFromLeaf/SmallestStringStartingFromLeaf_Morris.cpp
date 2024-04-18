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
    string smallestFromLeaf(TreeNode* root) {
        // Morris

        // if predecessor->right == NULL, predecessor->right = root, and
        // visit root->left else, revert the change, visit root, and visit
        // root->right

        string prefix;
        string min;

        // the right children of the last visited node will be NULL
        while (root) {
            if (!root->left) {
                prefix.insert(0, 1, 'a' + root->val);

                if (!root->right) { // the last visited node
                    if (min == "" || min.compare(prefix) > 0) {
                        min = prefix;
                    }
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

                    prefix.insert(0, 1, 'a' + root->val);
                    root = root->left; // visit root->left
                } else { // predecessor->right == root. which means left subtree
                         // have been visited
                    predecessor->right = NULL; // revert the change

                    if (!predecessor->left) { // if predecessor is a leaf
                        if (min == "" || min.compare(prefix) > 0) {
                            min = prefix;
                        }
                    }

                    prefix = prefix.substr(level);
                    root = root->right; // visit root->right
                }
            }
        }

        return min;
    }
};
