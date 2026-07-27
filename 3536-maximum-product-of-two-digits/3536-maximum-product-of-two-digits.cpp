class Solution {
public:
    int maxProduct(int n) {
        vector <int> digits;

        while (n > 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;
        }

        int length = digits.size();
        sort(digits.begin(), digits.end());

        return digits[length-1]*digits[length-2];
        
    }
};