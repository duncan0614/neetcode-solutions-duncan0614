class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(grid, r, c):
            if 0 <= r < len(grid) and 0 <= c < len(grid[0]):
                if grid[r][c] == "1":
                    grid[r][c] = "0"
                    for p in direction:
                        dfs(grid, r+p[0], c+p[1])

        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and (i, j):
                    dfs(grid, i, j)
                    ret += 1

        return ret
    
    

