class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Right, Left, Down, Up
        vector<pair<int,int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // Ignore stale entries
      //      if(cost > dist[x][y])
          //      continue;

            // Reached destination
            if(x == m-1 && y == n-1)
                return cost;

            for(int k=0;k<4;k++){

                int nx = x + dir[k].first;
                int ny = y + dir[k].second;

                if(nx<0 || nx>=m || ny<0 || ny>=n)
                    continue;

                int wt = (grid[x][y] == k+1) ? 0 : 1;

                if(dist[nx][ny] > cost + wt){

                    dist[nx][ny] = cost + wt;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }

        return dist[m-1][n-1];
    }
};