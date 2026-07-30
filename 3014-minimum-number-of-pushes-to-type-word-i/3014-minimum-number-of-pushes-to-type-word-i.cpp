class Solution {
public:
    int minimumPushes(string word) {
        if (word.length() < 9) {
            return word.length();
        } else if (9 <= word.length() && word.length() <= 16) {
            return 8 + ((word.length() - 8) * 2);
        } else if (16 < word.length() && word.length() <= 24) {
            return 24 + ((word.length() - 16) * 3);
        } else {
            return 48 + ((word.length() - 24) * 4);
        }
    }
};