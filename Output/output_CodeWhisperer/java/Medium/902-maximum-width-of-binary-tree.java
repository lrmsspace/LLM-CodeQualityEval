/**https://leetcode.com/problems/maximum-width-of-binary-tree/ */
//Given the root of a binary tree, return the maximum width of the given tree.
//The maximum width of a tree is the maximum width among all levels.
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
//It is guaranteed that the answer will in the range of a 32-bit signed integer.
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: 4
//Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
//Example 2:
//Input: root = [1,3,2,5,null,null,9,6,null,7]
//Output: 7
//Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
//Example 3:
//Input: root = [1,3,2,5]
//Output: 2
//Explanation: The maximum width exists in the second level with length 2 (3,2).
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 3000].
//	-100 <= Node.val <= 100
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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(root, 0));
        int max = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            int start = 0, end = 0;
            for (int i = 0; i < size; i++) {
                Pair<TreeNode, Integer> pair = q.poll();
                TreeNode node = pair.getKey();
                int index = pair.getValue();
                if (i == 0) start = index;
                if (i == size - 1) end = index;
                if (node.left != null) q.offer(new Pair<>(node.left, 2 * index + 1));
                if (node.right != null) q.offer(new Pair<>(node.right, 2 * index + 2));
            }
            max = Math.max(max, end - start + 1);
        }
        return max;
        
    }
}