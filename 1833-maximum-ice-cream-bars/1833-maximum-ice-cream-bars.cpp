class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cntArr(*max_element(costs.begin(), costs.end()) + 1, 0);

        for (int i = 0; i < costs.size(); ++i) {
            cntArr[costs[i]]++;
        }

        for (int i = 1; i < cntArr.size(); ++i) {
            cntArr[i] += cntArr[i-1];
        }

        vector<int> sorted(costs.size());

        for (int i = costs.size() - 1; i >= 0; i--) {
            sorted[cntArr[costs[i]] - 1] = costs[i];
            cntArr[costs[i]]--;
        }

        int max_ice_cream = 0;
        for (int num : sorted) {
            if (num <= coins) {
                max_ice_cream++;
                coins -= num;
            }
        }

        return max_ice_cream;
        
    }
};