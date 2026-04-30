class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def dfs(i, j, k, cur, visited):
            if cur == word:
                return True
            
            if i >= 0 and i < len(board) and j >= 0 and j < len(board[0]) and (i, j) not in visited:
                if board[i][j] == word[k]:
                    cur += word[k]
                    k += 1
                    visited.append((i, j))

                    if dfs(i + 1, j, k, cur, visited) or dfs(i - 1, j, k, cur, visited) \
                    or dfs(i, j + 1, k, cur, visited) or dfs(i, j - 1, k, cur, visited):
                        return True
                    else:
                        visited.pop()
            
            return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0, "", []):
                    return True

        return False


