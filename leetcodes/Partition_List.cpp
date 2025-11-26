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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        
        ListNode *lessHead = nullptr, *lessTail = nullptr;
        ListNode *greaterHead = nullptr, *greaterTail = nullptr;

        ListNode *temp = head;
        while (temp) {
            ListNode *next = temp->next;
            temp->next = NULL;   

            if (temp->val < x) {
                if (!lessHead) lessHead = lessTail = temp;
                else lessTail = lessTail->next = temp;
            } else {
                if (!greaterHead) greaterHead = greaterTail = temp;
                else greaterTail = greaterTail->next = temp;
            }
            temp = next;
        }

        if (!lessHead) return greaterHead;

        lessTail->next = greaterHead;
        return lessHead;
    }
};
