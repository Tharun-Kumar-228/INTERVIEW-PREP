public class Main {
    public static void main(String[] args) {
        ListNode common = new ListNode(8, new ListNode(4, new ListNode(5)));
        ListNode headA = new ListNode(4, new ListNode(1, common));
        ListNode headB = new ListNode(5, new ListNode(6, new ListNode(1, common)));
        Solution solution = new Solution();
        ListNode intersection = solution.getIntersectionNode(headA, headB);
        if (intersection != null) {
            System.out.println("Intersected at '" + intersection.val + "'");
        } else {
            System.out.println("No intersection");
        }
    }
}
