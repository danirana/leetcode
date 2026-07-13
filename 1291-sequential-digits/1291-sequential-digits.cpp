class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> sequential_numbers;
        for (int i = 2; i <= 9; ++i) {
            for (int start = 0; start + i <= 9; ++start) {
                int num = stoi(s.substr(start, i));
                if (num >= low && num <= high) sequential_numbers.push_back(num);
            }
        }
        return sequential_numbers;
    }
};