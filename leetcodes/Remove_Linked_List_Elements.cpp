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
    ListNode* removeElements(ListNode* head, int val) {
        // while(head && head->val == val){
        //     head = head->next;
        // }
        // if(head == NULL) return NULL;

        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        
        ListNode *temp =head,*prev=fake_head;
        prev->next = head;
        while(temp!=NULL){
            if(temp->val == val){
                prev->next = temp->next;
                temp=temp->next;
                continue;
            }
            prev = temp;
            temp= temp->next;
        }
        return fake_head->next;

    }
};