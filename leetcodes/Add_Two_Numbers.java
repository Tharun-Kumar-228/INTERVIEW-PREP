/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

    int carry=0;
    ListNode dummy = new ListNode(0);
    ListNode temp = dummy;
    while(l1!=null && l2 !=null){
        int val = l1.val + l2.val + carry ;
        carry = val/10;
        val = val%10;
        ListNode t = new ListNode(val);
        temp.next = t;
        temp = temp.next;
        l1=l1.next;
        l2=l2.next;
    }
    if(l1!=null){
      temp.next= l1;
      while(l1!=null){
        int val = l1.val;
        val = val+carry;
        carry = val /10;
        val = val%10;
        l1.val = val;
        l1=l1.next;
      }  
    }
if(l2!=null){
      temp.next= l2;
      while(l2!=null){
        int val = l2.val;
        val = val+carry;
        carry = val /10;
        val = val%10;
        l2.val = val;
        l2=l2.next;
      }  
    }
    if(carry !=0){
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = new ListNode(carry);
    }
        return dummy.next;
    }
}