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
        int res=0;
        while (head) {
            head = head->next;
            res++;
        }
        return res;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head->next == nullptr) return head;
        vector<int> nodes;
        while(head) {
            nodes.push_back(head->val);
            head = head->next;
        }
        // int n = nodes.size();
        int l = 0, r = nodes.size() - 1;
                // cout << "Before: l = " << l << ", r = " << r << "\n";

        while(k > 1) {
            l++;
            r--;
            k--;
        }
        // cout << "After: l = " << l << ", r = " << r << "\n";
        swap(nodes[l], nodes[r]);
        ListNode* resHead = new ListNode(0);
        ListNode* resTail = resHead;
        for (int node: nodes) {
            ListNode* temp = new ListNode(node);
            resTail->next = temp;
            resTail = resTail->next;
        }
        return resHead->next;
    }
};