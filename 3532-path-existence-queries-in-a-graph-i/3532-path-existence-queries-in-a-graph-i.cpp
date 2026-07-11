class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // n is the number of nodes
        // nums allows duplicates
        // undirected if absolute difference is at most max diff
        // return an array of booleans if if there a path between

        vector<int> components(n, 0);
        vector<bool> answer(queries.size(), false);

        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                components[i] = components[i-1];
            } else {
                components[i] = components[i-1] + 1;
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            int node1 = queries[i][0];
            int node2 = queries[i][1];
            if (components[node1] == components[node2]) {
                answer[i] = true;
            }
        }

        return answer;

    }
};