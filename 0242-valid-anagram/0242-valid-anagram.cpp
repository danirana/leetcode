class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_letters;

        for (char c : s) {
            s_letters[c]++;
        }

        for (char c : t) {
            if (s_letters.contains(c) && s_letters[c] != 0) {
                s_letters[c] -= 1;
                continue;
            }
            return false;
        }

        bool hasNonZero = any_of(s_letters.begin(), s_letters.end(), [](const auto& pair) {
            return pair.second != 0;
        });

        return (hasNonZero) ? false : true;
        
    }
};