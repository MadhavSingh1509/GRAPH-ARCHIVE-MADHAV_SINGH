class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,
                                         vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<vector<pair<int,int>>> adj(n);

        // color: 0 = Red, 1 = Blue
        for (auto &e : redEdges)
            adj[e[0]].push_back({e[1], 0});

        for (auto &e : blueEdges)
            adj[e[0]].push_back({e[1], 1});

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(2, INF));

        queue<tuple<int,int,int>> q;
        // (distance, node, lastColor)
        q.push({0, 0, -1});

        while (!q.empty()) {

            auto [d, u, lastColor] = q.front();
            q.pop();

            for (auto [v, color] : adj[u]) {

                if ((lastColor == -1 || color != lastColor)
                    && d + 1 < dist[v][color]) {

                    dist[v][color] = d + 1;
                    q.push({d + 1, v, color});
                }
            }
        }

        vector<int> ans(n);
        ans[0] = 0;

        for (int i = 1; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            ans[i] = (best == INF ? -1 : best);
        }

        return ans;
    }
};