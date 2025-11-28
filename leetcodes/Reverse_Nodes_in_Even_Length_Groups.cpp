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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *temp = head;   
        ListNode *start = dummy;
        ListNode *p1 = NULL;

        int group = 1;

        while (temp) {

            int count = 0;
            p1 = start;        
            for (int i = 0; temp && i < group; i++) {
                p1 = temp;
                temp = temp->next;
                count++;
            }
            if (count % 2 == 0) {

                ListNode *curr = start->next;
                ListNode *prev = temp;   
                ListNode *next = NULL;

                ListNode *preservehead = start->next;
                ListNode *preservetail = temp;
                while (curr != temp) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                start->next = prev;
                preservehead->next = preservetail;

                start = preservehead;
            }
            else {
                start = p1;
            }

            group++;
        }

        return dummy->next;
    }
};
