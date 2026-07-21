class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bobTime;
    int ans = INT_MIN;

    bool dfsBob(int node, int par, int time) {
        if (node == 0) {
            bobTime[node] = time;
            return true;
        }
bool ans=false;
        for (int nei : adj[node]) {
            if (nei == par) continue;

            if (dfsBob(nei, node, time + 1)) {
                bobTime[node] = time;
                ans=ans||true;
            }
        }

        return ans;
    }

    void dfsAlice(int node, int par, int time, int income,
                  vector<int>& amount) {

        if (time < bobTime[node])
            income += amount[node];
        else if (time == bobTime[node])
            income += amount[node] / 2;

        bool leaf = true;

        for (int nei : adj[node]) {
            if (nei == par) continue;
            leaf = false;
            dfsAlice(nei, node, time + 1, income, amount);
        }

        if (leaf)
            ans = max(ans, income);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {

        int n = amount.size();

        adj.resize(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        bobTime.assign(n, INT_MAX);

        dfsBob(bob, -1, 0);

        dfsAlice(0, -1, 0, 0, amount);

        return ans;
    }
};