/**https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
// 
//Example 1:
//Input: root = [4,2,6,1,3]
//Output: 1
//Example 2:
//Input: root = [1,0,48,null,null,12,49]
//Output: 1
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 104].
//	0 <= Node.val <= 105
// 
//Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    public int getMinimumDifference(TreeNode root) {
        int minDiff = Integer.MAX_VALUE;
        List<Integer> values = new ArrayList<>();
        inorder(root, values);
        
        for (int i = 1; i < values.size(); i++) {
            minDiff = Math.min(minDiff, values.get(i) - values.get(i - 1));
        }
        
        return minDiff;
        
    }
}