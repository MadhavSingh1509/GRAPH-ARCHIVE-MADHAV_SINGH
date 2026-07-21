class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        // Min distance to reach the END of each special road
        int n = specialRoads.size();
        vector<int> dist(n, INT_MAX);

        // {cost till reaching end of road, road index}
        priority_queue<pair<int,int>, vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        // Worst case: walk directly to target
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);

        // Initialize:
        // Reach every special road's start by walking,
        // then take that road.
        for(int i = 0; i < n; i++) {

            int cost =
                abs(start[0] - specialRoads[i][0]) +
                abs(start[1] - specialRoads[i][1]) +
                specialRoads[i][4];

            dist[i] = cost;
            pq.push({cost, i});
        }

        while(!pq.empty()) {

            auto [curCost, idx] = pq.top();
            pq.pop();

            if(curCost > dist[idx])
                continue;

            // Current position = end of this special road
            int x = specialRoads[idx][2];
            int y = specialRoads[idx][3];

            // From here, simply walk to target
            ans = min(ans,
                      curCost +
                      abs(x - target[0]) +
                      abs(y - target[1]));

            // Try taking every other special road next
            for(int j = 0; j < n; j++) {

                int nx = specialRoads[j][0];
                int ny = specialRoads[j][1];

                // Walk from current road's end
                // to next road's start,
                // then take that road
                int newCost =
                    curCost +
                    abs(x - nx) +
                    abs(y - ny) +
                    specialRoads[j][4];

                if(newCost < dist[j]) {
                    dist[j] = newCost;
                    pq.push({newCost, j});
                }
            }
        }

        return ans;
    }
};