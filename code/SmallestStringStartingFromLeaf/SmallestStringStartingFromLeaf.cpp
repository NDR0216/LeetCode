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
    string smallestFromLeaf_(TreeNode* root, string prefix) {
        if (!root) {
            return "";
        }

        prefix.insert(0, 1, 'a' + root->val);

        if (!root->left && !root->right) { // leaf node
            return prefix;
        }

        string left = smallestFromLeaf_(root->left, prefix);
        string right = smallestFromLeaf_(root->right, prefix);

        if (left == "") {
            return right;
        }
        if (right == "") {
            return left;
        }

        if (left.compare(right) >= 0) { // left >= right
            return right;
        } else { // left < right
            return left;
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        return smallestFromLeaf_(root, "");
    }
};
