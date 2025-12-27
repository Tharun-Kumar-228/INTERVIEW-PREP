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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        int n = 0;
        ListNode curNode = head;
        while (curNode != null) {
            n++;
            curNode = curNode.next;
        }
        int[] sub = new int[n];
        curNode = head;
        for (int i = 0; i < n; i++, curNode = curNode.next) {
            sub[i] = curNode.val;
        }
        int[] next = getNext(sub);
        return checkPath(root, 0, sub, next);
    }

    public int[] getNext(int[] sub) {
        int n = sub.length;
        int[] next = new int[n];
        next[0] = -1;
        int cur = 0;
        int i = 2;
        while (i < n) {
            if (sub[i - 1] == sub[cur]) {
                next[i++] = ++cur;
            } else if (cur != 0) {
                cur = next[cur];
            } else {
                i++;
            }
        }
        return next;
    }

    public boolean checkPath(TreeNode root, int cur, int[] sub, int[] next) {
        if (cur == sub.length) return true;
        if (root == null) return false;
        if (root.val == sub[cur]) {
            return checkPath(root.left, cur + 1, sub, next) || checkPath(root.right, cur + 1, sub, next);
        } else if (cur != 0){
            return checkPath(root, next[cur], sub, next);
        } else {
            return checkPath(root.left, 0, sub, next) || checkPath(root.right, 0, sub, next);
        }
    }
}