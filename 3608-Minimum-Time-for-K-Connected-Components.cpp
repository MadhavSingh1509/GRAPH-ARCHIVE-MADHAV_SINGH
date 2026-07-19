class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool check(int t, int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int comp = n;

        for (auto &e : edges) {
            if (e[2] > t) {
                if (unite(e[0], e[1]))
                    comp--;
            }
        }

        return comp >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {

        int mx = 0;
        for (auto &e : edges)
            mx = max(mx, e[2]);

        if (check(0, n, edges, k))
            return 0;

        int l = 1, r = mx;
        int ans = mx;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, edges, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};