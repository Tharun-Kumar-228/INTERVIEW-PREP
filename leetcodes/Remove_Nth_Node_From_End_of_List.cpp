class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* loc = head;

        for(int i = 0; i < n; i++){
            ptr = ptr->next;
        }

        if(ptr == NULL){
            ListNode * temp = head;
            head = head->next;
            delete temp;
            return head;

        }


        while(ptr->next != NULL){
            ptr = ptr->next;
            loc = loc->next;
        }

        loc->next = loc->next->next;

        return head;
    }
};
