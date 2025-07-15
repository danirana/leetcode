class Solution {
public:
    bool isValid(string word) {
        
        if (word.length() < 3) {
            return false;
        }

        int vowels = 0;
        int consonants = 0;
        string vowelsList = "aeiouAEIOU";

        for (char c : word) {
            if (isalpha(c)) {
                if (vowelsList.find(c) != string::npos) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }

        return vowels >= 1 && consonants >= 1;
    }
};