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
        if(!head) return head;
        Node * temp = head;
        while(temp){
            Node * newNode = new Node(temp->val);
            Node * next = temp->next;
            temp->next = newNode;
            newNode->next = next;
            temp = next;
        }

        Node *fh = head;
        Node *sh = head->next;
        while(fh && sh){
            sh->random = (fh->random)?fh->random->next:NULL;
            fh = sh->next;
            sh = (fh == NULL)?NULL:fh->next;
        }

        temp = head;
        while(temp){
            cout<< temp->val<<"->";
            temp = temp->next;
        }

        cout<<"NULL";
        temp= head->next;
        fh = head;
        sh = head->next;
        while(fh){
            fh->next = sh->next;
            fh = fh->next;
            sh->next = fh?fh->next:NULL;
            sh=sh->next;
        }
        return temp;
    }
};