class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max = 2048; // every xor is under 2048

        int n = nums.size();
        vector<char> pairs(max, 0), triplets(max, 0);

        // go through every i and j pair and store them so only distinct pairs are kept
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                pairs[nums[i] ^ nums[j]] = 1;

        // go through distinct pairs 
        for (int p = 0; p < max; ++p)
            if (pairs[p])
                // do the last xor
                for (int k = 0; k < n; ++k)
                    triplets[p ^ nums[k]] = 1;

        return count(triplets.begin(), triplets.end(), (char)1);
    }
};