

//LEETCODE HARD:834
//This was a very good problem to LEARN
//I watched the solution of this problem on yt ,codestory with mik;
//sum of DISANCES in tree:
class Solution {
public:
    int N;
    int rootdist=0;
    vector<int>childcount;
    vector<int>ans;
    int rootdfs(vector<vector<int>>&adj,int node,int prev,int depth){
        int c=1;
        rootdist+=depth;
        for(auto child:adj[node]){
            if(child==prev)continue;
            c+=rootdfs(adj,child,node,depth+1);
        }
        childcount[node]=c;
        return c;
    }
    void dfs(vector<vector<int>>&adj,int parent,int prev){
    

    for(auto child:adj[parent]){
        if(child==prev)continue;
     ans[child]=ans[parent]-childcount[child]+(N-childcount[child]);
     dfs(adj,child,parent);
    }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    N=n;
    childcount.resize(N);
    ans.resize(N);
    vector<vector<int>>adj(N);
    for(auto p:edges){
        int u=p[0];
        int v=p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);


    }
    rootdfs(adj,0,-2,0);
    ans[0]=rootdist;
    dfs(adj,0,-2);

    return ans;


    }
};