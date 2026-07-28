class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        // the min total damage to get to each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        deque<pair<int,int>> dq;
        dq.push_back({0,0});

        while (!dq.empty()) {
            auto [r,c] = dq.front();
            dq.pop_front();

            // up
            if (r - 1 >= 0) {
                int neighbor_r = r - 1, neighbor_c = c;
                int neighbor_d = dist[r][c] + grid[neighbor_r][neighbor_c];
                if (neighbor_d < dist[neighbor_r][neighbor_c]) {
                    dist[neighbor_r][neighbor_c] = neighbor_d;
                    if (grid[neighbor_r][neighbor_c] == 0) dq.push_front({neighbor_r, neighbor_c});
                    else  dq.push_back({neighbor_r, neighbor_c});
                }
            }

            // down
            if (r + 1 < m) {
                int neighbor_r = r + 1, neighbor_c = c;
                int neighbor_d = dist[r][c] + grid[neighbor_r][neighbor_c];
                if (neighbor_d < dist[neighbor_r][neighbor_c]) {
                    dist[neighbor_r][neighbor_c] = neighbor_d;
                    if(grid[neighbor_r][neighbor_c] == 0) dq.push_front({neighbor_r, neighbor_c});
                    else dq.push_back({neighbor_r, neighbor_c});
                }
            }

            // left
            if (c - 1 >= 0) {
                int neighbor_r = r, neighbor_c = c - 1;
                int neighbor_d = dist[r][c] + grid[neighbor_r][neighbor_c];
                if (neighbor_d < dist[neighbor_r][neighbor_c]) {
                    dist[neighbor_r][neighbor_c] = neighbor_d;
                    if(grid[neighbor_r][neighbor_c] == 0) dq.push_front({neighbor_r, neighbor_c});
                    else dq.push_back({neighbor_r, neighbor_c});
                }
            }

            // right 
            if (c + 1 < n) {
                int neighbor_r = r, neighbor_c = c + 1;
                int neighbor_d = dist[r][c] + grid[neighbor_r][neighbor_c];
                if (neighbor_d < dist[neighbor_r][neighbor_c]) {
                    dist[neighbor_r][neighbor_c] = neighbor_d;
                    if(grid[neighbor_r][neighbor_c] == 0) dq.push_front({neighbor_r, neighbor_c});
                    else dq.push_back({neighbor_r, neighbor_c});
                }
            }

        }
        return dist[m-1][n-1] <= health - 1;

    }
};