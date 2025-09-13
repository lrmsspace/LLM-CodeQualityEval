/**https://leetcode.com/problems/find-largest-value-in-each-tree-row/ */
//Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: [1,3,9]
//Example 2:
//Input: root = [1,2,3]
//Output: [1,3]
// 
//Constraints:
//	The number of nodes in the tree will be in the range [0, 104].
//	-231 <= Node.val <= 231 - 1
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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                max = Math.max(max, node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            result.add(max);
        }
        return result;        
    }
}