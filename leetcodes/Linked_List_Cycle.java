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
    public boolean hasCycle(ListNode head) {
        ListNode fp = head;
        ListNode bp = head;
        while(fp != null && fp.next !=null){
            fp = fp.next.next;
            bp = bp.next;
            if(fp == bp){
                return true;
            }
        }
        return false;
    }
}