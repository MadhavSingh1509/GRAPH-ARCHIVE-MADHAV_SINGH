class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        
        vector<vector<int>>adj(n);
        for(int i=0;i<=n-2;i++)adj[i].push_back(i+1);

        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
            queue<pair<int,int>>q;
            q.push({0,0});
            vector<bool>vis(n,false);
            vis[0]=1;
            while(!q.empty()){
auto [d,node]=q.front();
q.pop();
if(node==n-1){ans.push_back(d);break;}
for(auto v:adj[node]){
if(vis[v]==false){q.push({d+1,v});vis[v]=true;}

}


            }
        }
        
        return ans;
    }
};