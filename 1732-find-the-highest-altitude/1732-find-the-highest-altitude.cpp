class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        vector<int> alts(gain.size() + 1, 0);
        alts[0] = 0;

        for (int i = 1; i < alts.size(); ++i) {
            alts[i] += alts[i-1] + gain[i - 1];
        }

        return *max_element(alts.begin(), alts.end());
    }
};