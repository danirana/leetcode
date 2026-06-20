class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (islower(c)) {
                result += c;
            } else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                } else continue;
            } else if (c == '#') {
                string duplicate = result;
                result += duplicate;
            } else {
                reverse(result.begin(), result.end());
            }
        }

        return result;
        
    }
};