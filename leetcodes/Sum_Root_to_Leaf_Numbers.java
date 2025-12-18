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
    public int sumNumbers(TreeNode root) {
        if(root==null)
        {
            return 0;
        }
        ArrayList<Integer> arr = new ArrayList<>();
        summer(root,arr,0); 
        int sum=0;     
        for(Integer a : arr)
        {
            sum=sum+a;
        }       
        return sum;
    }
    public void summer(TreeNode root, ArrayList<Integer> arr,int sum)
    {
        sum=sum*10+root.val;
        if(root.left!=null)
        {
            summer(root.left,arr,sum);
        }
        if(root.right!=null)
        {
            summer(root.right,arr,sum);
        }
        if(root.left==null && root.right==null)
        {
            arr.add(sum);
        }

    }
    
}