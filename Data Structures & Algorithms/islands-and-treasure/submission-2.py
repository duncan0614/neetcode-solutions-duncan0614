class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # run through 
        ROW = len(grid)
        COL = len(grid[0])
        q = deque()
        visited = set()

        def findRooms(r, c):
            if 0 <= r < ROW and 0 <= c < COL and grid[r][c] != -1 and (r, c) not in visited:
                visited.add((r, c))
                q.append((r, c))

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visited.add((r, c))
        
        step = 0
        while q:           
            for _ in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = step

                findRooms(r + 1, c)
                findRooms(r - 1, c)
                findRooms(r, c + 1)
                findRooms(r, c - 1)

            step += 1

        
            
