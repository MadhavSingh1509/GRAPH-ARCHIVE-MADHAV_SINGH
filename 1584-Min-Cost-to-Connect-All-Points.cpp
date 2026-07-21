class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //prim's algorithm ka revision ho gaya
        //minimum spanning tree
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});//wt,node
        int ans=0;
        while(!pq.empty()){
            auto [wt,u]=pq.top();
            pq.pop();
            if(vis[u])continue;
            vis[u]=1;
            ans+=wt;
            for(int v=0;v<n;v++){
                if(vis[v]==0){pq.push({abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]),v});}
            }
        }
return ans;
    }
};