class Solution {
    int direction[4][2] = {{1, 0}, {-1,0}, {0, 1}, {0, -1}};
    int maxArea = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    int curArea = 1;
                    bfs(grid, r, c, curArea);
                    maxArea = max(maxArea, curArea);
                }
                
            }
        }
        return maxArea;
    }

private:
    void bfs(vector<vector<int>>& grid, int r, int c, int& curArea) {
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first, c = node.second;
            for (int i = 0; i < 4; i++){
                int dr = r + direction[i][0];
                int dc = c + direction[i][1];
                if (dr >= 0 && dc >= 0 && dr < grid.size() && dc < grid[0].size() && grid[dr][dc] == 1) {
                    curArea += 1;
                    q.push({dr, dc});
                    grid[dr][dc] = 0;
                }
            }
        }
    }
};
