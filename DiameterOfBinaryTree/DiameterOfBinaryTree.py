# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def path(self, root):
        if root == None:
            return (1, 0)
        
        left_edge = 0
        right_edge = 0
        left_path = 0
        right_path = 0
        if root.left != None:
            (left_edge, left_path) = self.path(root.left)
        if root.right != None:
            (right_edge, right_path) = self.path(root.right)
        
        edge = max(left_edge, right_edge) + 1
        path = max(left_edge + right_edge, left_path, right_path)
        
        return (edge, path)
        
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        (edge , diameter) = self.path(root)
        
        return diameter
