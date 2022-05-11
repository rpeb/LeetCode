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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* p = head;
        int len = 1;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;
        p->next = head;
        cout << "p->val = " << p->val << ", p->next->val = " << p->next->val << "\n";
        p = head;
        int nullAfter = len - k -1;
        while (nullAfter--) {
            p = p->next;
        }
        cout << "p->val = " << p->val << ", p->next->val = " << p->next->val << "\n";

        ListNode* newHead = p->next;
        p->next = nullptr;
        return newHead;
    }
};