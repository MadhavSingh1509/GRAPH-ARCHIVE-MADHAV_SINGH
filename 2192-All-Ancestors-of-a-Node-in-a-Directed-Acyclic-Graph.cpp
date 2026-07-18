class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis, st);
        }

        st.push(u);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        // DFS Topological Sort
        vector<bool> vis(n, false);
        stack<int> st;

        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i, adj, vis, st);

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        // Ancestor sets
        vector<set<int>> anc(n);

        // Process nodes in topological order
        for (int u : topo) {

            for (int v : adj[u]) {

                
                anc[v].insert(u);

                
                anc[v].insert(anc[u].begin(), anc[u].end());
            }
        }

        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = vector<int>(anc[i].begin(), anc[i].end());

        return ans;
    }
};