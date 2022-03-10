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
        
        // point to the second node of both lists
        ListNode* head1 = l1->next;
        ListNode* head2 = l2->next;
        
        int carry = 0;
        int sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        
        // initialize resulting list with the sum of first nodes
        ListNode* resHead = new ListNode(sum);
        
        
        // to append to the resulting list in O(1)
        ListNode* resTail = resHead;
        
        // start iterating both lists from second node
        while (head1 != nullptr or head2 != nullptr) {
            // cout << "carry in while = " << carry << "\n";
            int f = 0, s = 0;
            if (head1 != nullptr) {
                f = head1->val;
                head1 = head1->next;
            }
            if (head2 != nullptr) {
                s = head2->val;
                head2 = head2->next;
            }
            sum = f + s + carry;
            carry = sum / 10;
            sum = sum % 10;
            resTail->next = new ListNode(sum);
            resTail = resTail->next;
        }
        cout << "carry after while = " << carry << "\n";
        if (carry) {
            resTail->next = new ListNode(carry);
        }
        return resHead;
    }
};