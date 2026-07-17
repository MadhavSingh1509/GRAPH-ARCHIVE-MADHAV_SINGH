class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    // First DFS:
    // Compute answer when root = 0
    void dfs1(int node, int par) {

        for (auto [v, cost] : adj[node]) {

            if (v == par) continue;

            ans[0] += cost;

            dfs1(v, node);
        }
    }

    // Second DFS:
    // Reroot DP
    void dfs2(int node, int par) {

        for (auto [v, cost] : adj[node]) {

            if (v == par) continue;

            if (cost == 0)
                ans[v] = ans[node] + 1;
            else
                ans[v] = ans[node] - 1;

            dfs2(v, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        adj.assign(n, {});
        ans.assign(n, 0);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            // original edge u -> v
            adj[u].push_back({v, 0});

            // reverse traversal needs one reversal
            adj[v].push_back({u, 1});
        }

        dfs1(0, -1);

        dfs2(0, -1);

        return ans;
    }
};