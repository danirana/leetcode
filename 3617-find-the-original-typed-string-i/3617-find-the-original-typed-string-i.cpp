class Solution {
public:
    int possibleStringCount(string word) {
        int totalPossible = 1;

        for (int i = 1; i < word.length(); ++i) {
            if (word.at(i - 1) == word.at(i)) {
                totalPossible++;
            }
        }
        
        return totalPossible;
    }
};