class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int half = (left + right)/2;

        while (left != right) {
            if (nums[right] > nums[half]) {
                right = half;  
            } else {
                left = half + 1;
            }
            half = (right + left) / 2;
        }
        return nums[right];
    }
};