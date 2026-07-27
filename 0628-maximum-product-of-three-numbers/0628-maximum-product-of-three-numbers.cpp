class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int top3   = nums[n-1] * nums[n-2] * nums[n-3];
        int bottom2 = nums[0] * nums[1] * nums[n-1];

        return max(top3, bottom2);
    }
};