class Solution {
public:
int c;
void f(int n,vector<vector<pair<int,int>>>&adj,int node,int par){


for(auto it:adj[node]){
int v=it.first;
int dir=it.second;
if(v==par)continue;
if(dir==1)c++;
f(n,adj,v,node);
}

}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        c=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,-1});
        }
        f(n,adj,0,-1);
        return c;
    }
};