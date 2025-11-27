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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode t1 = new ListNode(0);
        ListNode temp =t1;
        temp.next = head;
        int i;
        for(i=1;i<left;i++){
            temp = temp.next;
        }
        ListNode start = temp;
        ListNode curr = temp.next,endPrev= temp.next;
        ListNode prev = null;
        ListNode next = null;
        for(;i<=right;i++){
            temp = temp.next;
        }
        ListNode sp = temp.next;
        while(curr != sp){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        start.next = prev;
        endPrev.next= curr;
        return t1.next;
        
    }
}