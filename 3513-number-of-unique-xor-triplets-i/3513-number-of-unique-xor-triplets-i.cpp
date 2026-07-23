class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int bits = 0;
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        while (n > 0) {
            bits++;
            n /= 2;
        }

        return 1 << bits; 
        
    }
};