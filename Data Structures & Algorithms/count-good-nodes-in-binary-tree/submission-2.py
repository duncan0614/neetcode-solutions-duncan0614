# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:     
        currMax = root.val
        def dfs(node, maxNum):
            if not node:
                return 0
            
            if node.val >= maxNum:
                maxNum = node.val
                return 1 + dfs(node.left, maxNum) + dfs(node.right, maxNum)
            
            return 0 + dfs(node.left, maxNum) + dfs(node.right, maxNum)
        
        return dfs(root, currMax)
