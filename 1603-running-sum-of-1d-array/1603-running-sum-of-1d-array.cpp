class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> sum;
        sum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
             sum.push_back(nums[i] + sum[i - 1]);
        }

        return sum;
    }
};