class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (string word : words) {
            int new_letter = 0;

            for (char c : word) {
                new_letter += weights[c - 'a'];
            }
            
            new_letter = new_letter % 26;
            char letter = 'z' - new_letter;
            result += letter;
        }

        return result;
        
    }
};