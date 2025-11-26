class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        tail->next = head;
        k = k % len;
        int steps = len - k; 

        ListNode* newTail = head;
        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
