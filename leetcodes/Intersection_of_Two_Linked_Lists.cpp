/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (!headA || !headB) return nullptr;

       
        ListNode* tailA = headA;
        while (tailA->next) {
            tailA = tailA->next;
        }

       
        tailA->next = headB;

       
        ListNode* slow = headA;
        ListNode* fast = headA;
        ListNode* meet = nullptr;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                meet = slow;
                break;
            }
        }

        if (!meet) { 
          
            tailA->next = nullptr; 
            return nullptr;
        }

        slow = headA;
        while (slow != meet) {
            slow = slow->next;
            meet = meet->next;
        }
        tailA->next = nullptr;

        return slow;
    }
};
