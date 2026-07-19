class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        set<pair<int,int>> pq;   // {time, node}
        pq.insert({0, 0});

        vector<int> time(n, INT_MAX);
        time[0] = 0;

        vector<vector<tuple<int,int,int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int start = it[2];
            int finish = it[3];
            adj[u].push_back({v, start, finish});
        }

        while (!pq.empty()) {
            auto [t, node] = *pq.begin();
            pq.erase(pq.begin());

            if (node == n - 1)
                return t;

            for (auto [v, start, finish] : adj[node]) {
                if (t >= start && t <= finish) {
                    if (t + 1 < time[v]) {
                        pq.insert({t + 1, v});
                        time[v] = t + 1;
                    }
                } else if(t<start) pq.insert({start+1, v});
                
            }
        }

        return -1;
    }
};