/**https://leetcode.com/problems/longest-univalue-path/ */
//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
//The length of the path between two nodes is represented by the number of edges between them.
// 
//Example 1:
//Input: root = [5,4,5,1,1,null,5]
//Output: 2
//Explanation: The shown image shows that the longest path of the same value (i.e. 5).
//Example 2:
//Input: root = [1,4,5,4,4,null,5]
//Output: 2
//Explanation: The shown image shows that the longest path of the same value (i.e. 4).
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 104].
//	-1000 <= Node.val <= 1000
//	The depth of the tree will not exceed 1000.
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
    public int longestUnivaluePath(TreeNode root) {
        if(root==null)
            return 0;
        int[] max=new int[1];
        longestUnivaluePath(root,max);
        return max[0];
    }
    public int longestUnivaluePath(TreeNode root,int[] max){
        if(root==null)
            return 0;
        int left=longestUnivaluePath(root.left,max);
        int right=longestUnivaluePath(root.right,max);
        int left1=root.left!=null&&root.left.val==root.val?left+1:0;
        int right1=root.right!=null&&root.right.val==root.val?right+1:0;
        max[0]=Math.max(max[0],left1+right1);
        return Math.max(left1,right1);
    }
}