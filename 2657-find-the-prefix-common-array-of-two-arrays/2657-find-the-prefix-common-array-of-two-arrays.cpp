class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> A_elements;
        unordered_map<int, int> B_elements;
        vector<int> prefix_common_array(A.size());
        int common_ints = 0;

        for (int i = 0; i < prefix_common_array.size(); ++i) {
            A_elements[A[i]] = 0;
            B_elements[B[i]] = 0;

            if (A[i] == B[i]) {
                common_ints += 1;
                A_elements[B[i]] = 1;
                B_elements[A[i]] = 1;
            }

            if (A_elements.count(B[i]) && A_elements.at(B[i]) == 0) {
                common_ints += 1;
                A_elements[B[i]] = 1;
            }

            if (B_elements.count(A[i]) && B_elements.at(A[i]) == 0) {
                common_ints += 1;
                B_elements[A[i]] = 1;
            }

            prefix_common_array[i] = common_ints;
        }

        return prefix_common_array;
    }
};