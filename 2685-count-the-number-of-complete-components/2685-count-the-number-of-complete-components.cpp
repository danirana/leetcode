class Solution {
public:
    void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &comp) {
        visited[s] = true;
        comp.push_back(s);
        for (int nxt : adj[s])
            if (!visited[nxt])
                dfsRec(adj, visited, nxt, comp);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;                   
                dfsRec(adj, visited, i, component);    

                int k = component.size();
                int edgeCount = 0;
                for (int v : component)
                    edgeCount += adj[v].size();      // sums degrees; each edge counted twice
                edgeCount /= 2;

                if (edgeCount == k * (k - 1) / 2)
                    count++;
            }
        }

        return count;
    }
};