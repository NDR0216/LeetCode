# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:  
    def insert(self, node, n):
        if node.val == 0:
            node.val = n
            return
        
        if n < node.val:
            if node.left == None:
                node.left = TreeNode(0)
            self.insert(node.left, n)
        else:
            if node.right == None:
                node.right = TreeNode(0)
            self.insert(node.right, n)
        
        return
    
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:  
        root = TreeNode(0)
        
        for i in preorder:
            self.insert(root, i)
        
        return root
