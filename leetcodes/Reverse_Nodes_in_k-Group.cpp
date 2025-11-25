class Solution {
public:

    ListNode* reverseList(ListNode* t1, ListNode* t2) {
        ListNode* temp = t2->next;
        t2->next = NULL;

        ListNode* curr = t1;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        t1->next = temp;
        return prev; // new head
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* t1 = prevGroupEnd->next;
            ListNode* t2 = prevGroupEnd;

            for (int i = 0; i < k; i++) {
                t2 = t2->next;
                if (!t2) return dummy->next;
            }

            ListNode* newHead = reverseList(t1, t2);

            
            prevGroupEnd->next = newHead;
            prevGroupEnd = t1;
        }
    }
};
