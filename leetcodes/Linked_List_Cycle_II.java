/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fp = head,bp = head;
        int flag =0;
        while(fp != null && fp.next != null){
            fp = fp.next.next;
            bp = bp.next;
            if(fp == bp){
                flag=1;
                break;
            }
        }
        if(flag ==1){
        bp = head;
        while(bp != fp){
            fp = fp.next;
            bp = bp.next;
        }
        return bp;
        }else{
            return null;
        }

    }
}