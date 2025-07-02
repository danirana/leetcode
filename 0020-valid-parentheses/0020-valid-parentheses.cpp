class Solution {
public:
    bool isValid(string s) {

        stack<char> chars;

        for (char c : s) {
            if (c == '(' || c == '{' 
                || c == '[') {
                chars.push(c);
            } else if (chars.empty() 
                        || c == ')' && chars.top()!= '('
                        || c == '}' && chars.top() != '{' 
                        || c == ']' && chars.top() != '['){
                return false;
            } else {
                chars.pop();
            }
        }
        return chars.empty();
    }
};