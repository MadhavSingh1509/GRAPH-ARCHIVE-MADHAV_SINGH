class Solution {
public:
//simple dijkastra
int m;
int n;
vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> q;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e8));
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int d=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==m-1&&y==n-1)return d;
            for(auto p:dirs){
                int nx=x+p[0];
                int ny=y+p[1];
                if(nx>=0&&ny>=0&&nx<m&&ny<n){
                    
                    int dis=grid[nx][ny];
             if(d+dis<dist[nx][ny]){q.push({d+dis,{nx,ny}});
             dist[nx][ny]=d+dis;}
                }
            }
        }
        return -1;
    }
};