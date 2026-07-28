class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);

        int less = 0, equal = 0;
        for (int num : nums) {
            if (num < pivot) less++;
            if (num == pivot) equal++;
        }
        
        int left = 0, middle = less, right = less + equal;
        for (int num : nums) {
            if (num < pivot) {
                result[left] = num;
                left++;
            } else if (num == pivot) {
                result[middle] = num;
                middle++;
            } else {
                result[right] = num;
                right++;
            }
        }
        return result;
    }
};