class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []

        def dfs(lCount:int, rCount:int, cur:str):
            if len(cur) == n*2:
                ret.append(cur[:])
                return
            
            if (lCount != n):
                dfs(lCount + 1, rCount, cur + "(")

            if (lCount > rCount):
                dfs(lCount, rCount + 1, cur + ")")

        dfs(0, 0, "")
        return ret