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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         // Create a dummy head for the result linked list
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values of the current nodes, or 0 if the list has ended
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of values and the carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;  // Calculate new carry
            int digit = sum % 10;  // Get the last digit of the sum

            // Add the new digit to the result list
            current->next = new ListNode(digit);
            current = current->next;

            // Move to the next nodes in l1 and l2 if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // The result list starts from the node after the dummy head
        return dummyHead->next;
    }
};