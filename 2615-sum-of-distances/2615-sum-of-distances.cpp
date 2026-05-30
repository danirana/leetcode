class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> elements; 

        for (int i = 0; i < nums.size(); ++i) {
            elements[nums[i]].push_back(i);
        }

        vector<long long> result(nums.size(), 0);
         for (auto &it : elements) {
            vector<int> &idx = it.second;
            int m = idx.size();

            if (m == 1) continue; 

            vector<long long> prefix(m, 0);
            prefix[0] = idx[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + idx[i];
            }

            long long totalSum = prefix[m - 1];

            for (int i = 0; i < m; i++) {
                long long leftSum = prefix[i];
                long long rightSum = totalSum - leftSum;

                long long leftCount = i;
                long long rightCount = m - i - 1;

                long long idxVal = idx[i];

                long long leftCost = idxVal * leftCount - (i > 0 ? prefix[i - 1] : 0);
                long long rightCost = rightSum - idxVal * rightCount;

                result[idx[i]] = leftCost + rightCost;
            }
        }

        return result;
        
    }
};