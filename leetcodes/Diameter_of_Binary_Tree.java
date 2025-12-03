class Solution {

    // public int diameterOfBinaryTree(TreeNode root) {
    //     if (root == null) return 0;
    //     return Math.max(
    //         height(root.right) + height(root.left),
    //         Math.max(diameterOfBinaryTree(root.right),
    //                  diameterOfBinaryTree(root.left))
    //     );
    // }

    // public int height(TreeNode root) {
    //     if (root == null) return 0;
    //     return 1 + Math.max(height(root.left), height(root.right));
    // }
private static int maxi=0;
    public static int diameter_helper(TreeNode root)
    {
        if(root==null) return 0;
        int lh=diameter_helper(root.left);
        int rh=diameter_helper(root.right);
        maxi=Math.max(maxi, lh+rh);
        return 1+Math.max(lh, rh);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        maxi=0;
        diameter_helper(root);
        return maxi;
    }
    
}
