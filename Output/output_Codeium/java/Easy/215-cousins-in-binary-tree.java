/**https://leetcode.com/problems/cousins-in-binary-tree/ */
//Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
//Two nodes of a binary tree are cousins if they have the same depth with different parents.
//Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
// 
//Example 1:
//Input: root = [1,2,3,4], x = 4, y = 3
//Output: false
//Example 2:
//Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
//Output: true
//Example 3:
//Input: root = [1,2,3,null,4], x = 2, y = 3
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 100].
//	1 <= Node.val <= 100
//	Each node has a unique value.
//	x != y
//	x and y are exist in the tree.
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
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) return false;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int levelSize = q.size();
            boolean xFound = false;
            boolean yFound = false;
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = q.poll();
                if (node.val == x) xFound = true;
                if (node.val == y) yFound = true;
                if (node.left != null && node.right != null) {
                    if ((node.left.val == x && node.right.val == y) || (node.left.val == y && node.right.val == x)) {
                        return false;
                    }
                }
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            if (xFound && yFound) return true;
        }
        return false;
    }
}