class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        //har node ka neighbours ko store krlo
        //maxm sum nikalo of <=k elements
        int ans=-1e5;
        int n=vals.size();
        map<int,vector<int>>m;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            m[u].push_back(vals[v]);
            m[v].push_back(vals[u]);
            ans=max(ans,max(vals[u],vals[v]));
        }
        for(int i=0;i<n;i++){
vector<int>&v=m[i];
sort(v.rbegin(),v.rend());
int temp=vals[i];
int val=vals[i];
int sz=v.size();
int minii=min(k,sz);
for(int j=0;j<minii;j++){
    val+=v[j];
    temp=max(temp,val);
}
ans=max(ans,temp);
        }
        return ans;
    }
};