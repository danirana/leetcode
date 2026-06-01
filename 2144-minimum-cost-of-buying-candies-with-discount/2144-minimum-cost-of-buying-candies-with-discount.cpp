class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end(), greater<int>());

        int min_cost = 0;

        for (int i = 0; i < cost.size(); ++i) {
            if (i % 3 != 2) { 
                min_cost += cost[i];
            }
        }

        return min_cost;
        
    }
};