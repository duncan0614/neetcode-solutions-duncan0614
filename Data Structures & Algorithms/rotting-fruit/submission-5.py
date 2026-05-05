class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        q = deque()
        ret = 0
        fresh = 0

        for r in range(ROW):
            for c in range(COL):
                if grid[r][c] == 2:
                    q.append((r,c))
                elif grid[r][c] == 1:
                    fresh += 1
        
        direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while q and fresh > 0:
            for _ in range(len(q)):
                r, c = q.popleft()
                for d in direction:
                    nr = r + d[0]
                    nc = c + d[1]
                    if 0 <= nr < ROW and 0 <= nc < COL and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        q.append((nr, nc))
                        fresh -= 1
            ret += 1
        
        return ret if fresh == 0 else -1