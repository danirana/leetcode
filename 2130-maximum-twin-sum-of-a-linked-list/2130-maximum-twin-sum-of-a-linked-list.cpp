/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<int> st;

        while (slow) {
            st.push(slow->val);
            slow = slow->next;
        }

        int ans = 0;
        ListNode* curr = head;

        while (!st.empty()) {
            ans = max(ans, curr->val + st.top());
            st.pop();
            curr = curr->next;
        }

        return ans;
        
    }
};