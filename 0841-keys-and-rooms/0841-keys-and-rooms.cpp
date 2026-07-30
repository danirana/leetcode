class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int starting, int& result) {
        visited[starting] = true;
        result++;

        for (int key : rooms[starting]) {
            if (visited[key] == false) {
                dfs(rooms, visited, key, result);
            }
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int rooms_visited = 0;
        dfs(rooms, visited, 0, rooms_visited);
        return (rooms_visited == rooms.size());
    }
};