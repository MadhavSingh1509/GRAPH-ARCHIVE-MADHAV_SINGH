class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>>adj(n);
        int ans=0;
        vector<int>indeg(n,0);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].insert(v);
            adj[v].insert(u);
            indeg[u]++;
            indeg[v]++;
        }
        for(int u=0;u<n;u++){
            for(int v=u+1;v<n;v++){
                int c=indeg[u]+indeg[v];
                if(adj[u].count(v))c--;
                ans=max(ans,c);
            }
        }
        
        return ans;

        //0---1---2----3
        //        |
        //        4        5-6-7
    }
};