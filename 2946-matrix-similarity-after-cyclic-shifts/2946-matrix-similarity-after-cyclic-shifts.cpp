class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int cols = mat[0].size();
        for (const auto& row : mat)
            for (int i = 0; i < cols; ++i)
                if (row[i] != row[(i + k) % cols])
                    return false;
        return true;
    }
};