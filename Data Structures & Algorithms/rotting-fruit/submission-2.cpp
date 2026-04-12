class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROW = 0, COL = 0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROW = grid.size();
        COL = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;
        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;
            for(int i = 0; i < size; i++) {
                auto& [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = row + directions[i][0], nc = col + directions[i][1];
                    if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    } 
                }
            } 
        }

        return fresh == 0 ? minutes : -1;
    }
};
