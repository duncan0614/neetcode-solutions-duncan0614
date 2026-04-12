# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and not subRoot:
            return True
        
        if not root or not subRoot:
            return False

        def match (node, subnode):
            if not node and not subnode:
                return True
            
            if not node or not subnode:
                return False

            if node.val != subnode.val:
                return False
            
            if not match(node.left, subnode.left) or not match(node.right, subnode.right):
                return False

            return True
        
        if root.val == subRoot.val and match(root, subRoot):
            return True
    
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)