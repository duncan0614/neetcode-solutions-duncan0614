class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = []

        def dfs(grid, r, c, visited):
            if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and (r, c) not in visited:
                visited.append((r, c))
                if grid[r][c] == "1":
                    for p in direction:
                        dfs(grid, r+p[0], c+p[1], visited)

        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and (i, j) not in visited:
                    dfs(grid, i, j, visited)
                    ret += 1

        return ret
    
    

