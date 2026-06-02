class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> frequencies(26, 0);

        for (char c : s) {
            frequencies[c - 'a']++;
        }

        for (char c : t) {
            frequencies[c - 'a']--;
        }

        for (int count : frequencies) {
            if (count != 0) return false;
        }
        
        return true;
    }
};