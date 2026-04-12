# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = deque()
        
        ret = []
        if not root:
            return ret
        q.append(root)
            
        while q:
            lvLen = len(q)    

            filled = False
            for i in range(lvLen):
                node = q.popleft()

                if not node:
                    continue

                if not filled:
                    ret.append(node.val)
                    filled = True
                
                q.append(node.right)
                q.append(node.left)
        
        return ret
        

            
            