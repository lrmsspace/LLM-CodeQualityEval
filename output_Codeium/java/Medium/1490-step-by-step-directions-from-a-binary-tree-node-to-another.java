/**https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/ */
//You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
//Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
//	'L' means to go from a node to its left child node.
//	'R' means to go from a node to its right child node.
//	'U' means to go from a node to its parent node.
//Return the step-by-step directions of the shortest path from node s to node t.
// 
//Example 1:
//Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
//Output: "UURL"
//Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
//Example 2:
//Input: root = [2,1], startValue = 2, destValue = 1
//Output: "L"
//Explanation: The shortest path is: 2 → 1.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	1 <= startValue, destValue <= n
//	startValue != destValue
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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder sb = new StringBuilder();
        dfs(root, startValue, destValue, sb);
        return sb.toString();
    }

    private void dfs(TreeNode node, int startValue, int destValue, StringBuilder sb) {
        if (node.val == startValue) {
            dfs2(node, destValue, sb);
            return;
        }
        if (node.left != null) {
            dfs(node.left, startValue, destValue, sb);
            if (sb.length() > 0) {
                sb.append('U');
                return;
            }
        }
        if (node.right != null) {
            dfs(node.right, startValue, destValue, sb);
            if (sb.length() > 0) {
                sb.append('U');
                return;
            }
        }
    }

    private void dfs2(TreeNode node, int destValue, StringBuilder sb) {
        if (node.val == destValue) {
            return;
        }
        if (node.left != null && node.left.val == destValue) {
            sb.append('L');
            return;
        }
        if (node.right != null && node.right.val == destValue) {
            sb.append('R');
            return;
        }
        if (node.left != null) {
            sb.append('L');
            dfs2(node.left, destValue, sb);
        }
        if (node.right != null) {
            sb.append('R');
            dfs2(node.right, destValue, sb);
        }
    }
}