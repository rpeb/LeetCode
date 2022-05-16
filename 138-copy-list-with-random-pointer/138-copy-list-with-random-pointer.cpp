/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *p = head, *tmp;
        while (p) {
            tmp = p->next;
            Node* copy = new Node(p->val);
            p->next = copy;
            copy->next = tmp;
            p = tmp;
        }
        p = head;
        while (p && p->next) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        // detaching copy list from original one
        p = head;
        Node* resHead = new Node(0);
        Node *copy, *resTail = resHead;
        while(p) {
            tmp = p->next->next;
            copy = p->next;
            resTail->next = copy;
            resTail = copy;
            p->next = tmp;
            p = tmp;
        }
        return resHead->next;
    }
};