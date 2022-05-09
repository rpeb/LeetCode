1. initialize fast and slow to head
2. advance fast n times
3. check if fast is null
4. if fast is null then return head->next (delete first node)
5. else while fast->next != null, advance slow and fast once each
6. slow now points to one element before the element to be deleted
7. slow->next = slow->next->next;
8. return head
​
​