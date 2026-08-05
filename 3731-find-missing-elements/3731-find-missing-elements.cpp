class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int first = *min_element(nums.begin(), nums.end());
        int last = *max_element(nums.begin(), nums.end());
        vector<bool> present_nums(last, false);
        for (int num : nums) {
            present_nums[num] = true;
        }

        vector<int> result;
        for (int i = 0; i < present_nums.size(); ++i) {
            if (i >= first && !present_nums[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};