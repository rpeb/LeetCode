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
int getNumberOfNodes(ListNode* head) {
    int cnt = 0;
    ListNode *q = head;
    while (q != nullptr) {
        cnt++;
        q = q->next;
    }
    return cnt;
}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *q = head, *r = head;
        int n = getNumberOfNodes(head);
        // cout << "numberOfNodes: " << n << "\n";
        k = k % n;
        if (!k) return head;
        int skip = k-1;
        while(skip>0) {
            r = r->next;
            skip--;
        }
        while (r != nullptr && r->next != nullptr) {
            q = q->next;
            r = r->next;
        }
        // cout << "r->val: " << r->val << "\n";
        r->next = head;
        // cout << "r->next->val: " << r->next->val << "\n";
        ListNode* it = q;
        while (n-- > 1) {
            it = it->next;
        }
        // cout << "it->val: " << it->val << "\n";
        it->next = nullptr;
        return q;
    }
};