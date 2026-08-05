class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) dfs(adj, visited, neighbor);
        }

    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // make adj list
        vector<vector<int>> adj(n);
        for (vector<int> invocation : invocations) {
            adj[invocation[0]].push_back(invocation[1]);
        }

        vector<bool> visited(n, false);
        // call dfs
        dfs(adj, visited, k);

        for (vector<int> invoc : invocations) {
            if (!visited[invoc[0]] && visited[invoc[1]]) {
                vector<int> all(n);
                for (int i = 0; i < n; i++) all[i] = i;
                return all;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) result.push_back(i);
        }
        return result;
    }
};