class Solution {
public:
int c;
void dfs(int node,vector<bool>&vis,set<int>&st,vector<vector<int>>&adj){
    vis[node]=true;
    c++;
    for(auto v:adj[node]){
        if(vis[v]==false&& !st.count(v))dfs(v,vis,st,adj);
    }
}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        set<int>st(restricted.begin(),restricted.end());
        for(auto it:edges){
         int u=it[0];
         int v=it[1];
         
         adj[u].push_back(v);
         adj[v].push_back(u);
        }
        c=0;
        vector<bool>vis(n,false);
        if(st.count(0))return 0;
        dfs(0,vis,st,adj);
        return c;
    }
};