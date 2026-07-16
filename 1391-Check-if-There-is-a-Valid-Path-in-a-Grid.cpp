class Solution {
public:
    // 1 -> left, right
    // 2 -> up, down
    // 3 -> left, down
    // 4 -> right, down
    // 5 -> left, up
    // 6 -> up, right

    int m, n;

    map<int, vector<pair<int,int>>> mp = {
        {1, {{0,-1}, {0,1}}},
        {2, {{-1,0}, {1,0}}},
        {3, {{0,-1}, {1,0}}},
        {4, {{0,1}, {1,0}}},
        {5, {{0,-1}, {-1,0}}},
        {6, {{-1,0}, {0,1}}}
    };

    bool valid(int x, int y){
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1)
                return true;

            int curr = grid[x][y];

            for(auto [dx,dy] : mp[curr]){
                int nx = x + dx;
                int ny = y + dy;

                if(!valid(nx,ny) || vis[nx][ny])
                    continue;

                // check whether the next cell connects back
                bool ok = false;
                for(auto [rdx,rdy] : mp[grid[nx][ny]]){
                    if(nx + rdx == x && ny + rdy == y){
                        ok = true;
                        break;
                    }
                }

                if(ok){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }
};