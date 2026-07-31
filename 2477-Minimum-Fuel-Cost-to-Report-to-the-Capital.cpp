class Solution {
public:
long long ans=0;
int seat;
vector<vector<int>>adj;
int dfs(int u,int p){
    int peep=1;
    for(auto v:adj[u]){
        if(v==p)continue;
peep+=dfs(v,u);
    }
if(u!=0)ans+=((peep+seat-1)/seat);
return peep;


}
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        seat=seats;
        int n=roads.size()+1;
        adj.resize(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        return ans;
    }
};