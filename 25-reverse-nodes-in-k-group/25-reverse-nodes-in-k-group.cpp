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
    ListNode* reverse(ListNode* first, ListNode* last) {
        if (first->next == last) return first;
        
        ListNode* node = reverse(first->next, last);
        first->next->next = first;
        first->next = nullptr;
        
        return node;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* kthnode = head;
        for (int i = 0; i < k; ++i) {
            if (!kthnode) return head;
            kthnode = kthnode->next;
        }
        ListNode* newHead = reverse(head, kthnode);
        head->next = reverseKGroup(kthnode, k);
        return newHead;
    }
};