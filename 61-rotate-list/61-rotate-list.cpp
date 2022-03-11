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
        r->next = head;
        ListNode* it = q;
        while (n-- > 1) {
            it = it->next;
        }
        it->next = nullptr;
        return q;
    }
};