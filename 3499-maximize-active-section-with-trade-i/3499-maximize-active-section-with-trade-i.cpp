class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string aug_s = '1' + s + '1';
        vector<int> lengths;
        vector<char> sections;

        int current_length = 1;
        char current_char = '1';
        for (int i = 1; i < aug_s.length(); ++i) {
            if (aug_s[i] != current_char) {
                lengths.push_back(current_length);
                sections.push_back(current_char);
                current_length = 1;
                current_char = aug_s[i];
            } else {
                current_length++;
            }
        }

        int base = 0;
        for (char c: s) {
            if (c == '1') base++;
        }

        int best_gain = 0;

        for (int i = 1; i < (int)(sections.size()) - 1; ++i) {
            if (sections[i] == '1') {
                best_gain = max(best_gain, lengths[i-1] + lengths[i+1]);
            }
        }

        return base + best_gain;
    }
};