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
 import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        Set<Integer> uniqueValues = new HashSet<>();
        ListNode current = head;
        while (current != null) {
            uniqueValues.add(current.val);
            current = current.next;
        }
        Integer[] array = uniqueValues.toArray(new Integer[0]);
        Arrays.sort(array);
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        for (int val : array) {
            curr.next = new ListNode(val);
            curr = curr.next;
        }
        return dummy.next;
    }
}
