class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> q;
        for (int i = 0; i < n; ++i) q.push(i);
        
        vector<int> result(n);
        for (int i =0; i < n; ++i) {
            int slot = q.front(); 
            q.pop();
            result[slot] = deck[i];

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};