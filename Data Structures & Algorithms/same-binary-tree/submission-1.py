# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def dfs(nodeP, nodeQ):
            if not nodeP and not nodeQ:
                return True
            if not nodeP or not nodeQ or nodeP.val != nodeQ.val:
                return False
            
            retL = dfs(nodeP.left, nodeQ.left)
            retR = dfs(nodeP.right, nodeQ.right)

            if not retL or not retR:
                return False 
            return True
        
        ret = dfs(p, q)
        return ret
        