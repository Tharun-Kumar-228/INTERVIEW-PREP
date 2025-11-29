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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* oddDummy = new ListNode(0);
        ListNode* evenDummy = new ListNode(0);

        ListNode* oddTail = oddDummy;
        ListNode* evenTail = evenDummy;

        ListNode* curr = head;
        int idx = 1;

        while (curr != nullptr) {
            if (idx % 2 == 1) {  
                oddTail->next = curr;
                oddTail = oddTail->next;
            } else {  
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            curr = curr->next;
            idx++;
        }
        evenTail->next = nullptr;
        oddTail->next = evenDummy->next;

        return oddDummy->next;
    }
};
