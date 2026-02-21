class Solution {
public:
//LEETCODE HARD:1697
//GOOD PROBLEM TO LEARN DSU AND CUSTOM COMPARATOR LAMBDA FUNCTION
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries) {

        parent.resize(n);
        rank.resize(n);

        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        auto lambda = [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        };

        sort(edgeList.begin(), edgeList.end(), lambda);
        sort(queries.begin(), queries.end(), lambda);

        vector<bool> ans(queries.size());
        int j = 0;

        for (int i = 0; i < queries.size(); i++) {
            auto &q = queries[i];
            int u = q[0], v = q[1], t = q[2], idx = q[3];

            while (j < edgeList.size() && edgeList[j][2] < t) {
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            ans[idx] = (find(u) == find(v));
        }

        return ans;
    }
};