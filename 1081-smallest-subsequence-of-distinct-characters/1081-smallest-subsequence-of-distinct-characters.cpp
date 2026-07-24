class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> last_index;

        // records the last index of each character
        for (int i = 0; i < s.length() ; ++i) {
            last_index[s[i]] = i; 
        }

        string sub = "";
        unordered_set<char> in_sub;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (in_sub.count(c)) continue;

            // pop larger chars that still appear later
            while (!sub.empty() && sub.back() > c && last_index[sub.back()] > i) {
                in_sub.erase(sub.back());
                sub.pop_back();
            }

            sub.push_back(c);
            in_sub.insert(c);
        }

        return sub;
        
    }
};