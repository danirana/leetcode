class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int min_int_common = INT_MAX;

        unordered_set<int> nums1_elements;

        for (int num : nums1) {
            nums1_elements.insert(num);
        }

        for (int num : nums2) {
            if (nums1_elements.count(num)) {
                min_int_common = min(num, min_int_common);
            }
        }

        return (min_int_common == INT_MAX) ? -1 : min_int_common;
        
    }
};