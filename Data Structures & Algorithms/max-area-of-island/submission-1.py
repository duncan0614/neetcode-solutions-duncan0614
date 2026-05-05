class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        direction = [(1, 0), (0, -1), (-1, 0), (0, 1)]
        maxArea = 0

        def dfs(grid, r, c):
            if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == 1:
                area = 1
                for d in direction:          
                    grid[r][c] = 0
                    area += dfs(grid, r + d[0], c + d[1])
                return area
            return 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                   maxArea = max(maxArea, dfs(grid, i, j))
        
        return maxArea