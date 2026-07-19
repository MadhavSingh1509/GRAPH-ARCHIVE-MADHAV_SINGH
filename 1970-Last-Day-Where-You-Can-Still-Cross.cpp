class Solution {
public:
    bool check(int day, int row, int col, vector<vector<int>>& cells) {

        vector<vector<int>> grid(row, vector<int>(col, 0));

        // mark flooded cells
        for (int i = 0; i < day; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        // start BFS from every land cell in first row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            if (x == row - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < row &&
                    ny >= 0 && ny < col &&
                    !vis[nx][ny] &&
                    grid[nx][ny] == 0) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int l = 0;
        int r = cells.size();
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, row, col, cells)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};