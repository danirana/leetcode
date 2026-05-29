class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_value = INT_MAX;

        for (int num : nums) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            min_value = min(min_value, sum);
        }
        return min_value;
    }
};