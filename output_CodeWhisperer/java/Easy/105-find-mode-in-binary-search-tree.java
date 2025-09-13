/**https://leetcode.com/problems/find-mode-in-binary-search-tree/ */
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//If the tree has more than one mode, return them in any order.
//Assume a BST is defined as follows:
//	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//	Both the left and right subtrees must also be binary search trees.
// 
//Example 1:
//Input: root = [1,null,2,2]
//Output: [2]
//Example 2:
//Input: root = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
// 
//Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
import java.util.Stack;
import java.util.HashMap;
import java.util.Map;
class Solution {
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> map = new HashMap<>();
        int max = 0;
        int count = 0;
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack<>();
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            int c = map.getOrDefault(node.val, 0) + 1;
            map.put(node.val, c);
            if (c > max) {
                max = c;
                count = 1;
            } else if (c == max) {
                count++;
            }
            node = node.right;
        }
        int[] res = new int[count];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == max) {
                res[i++] = entry.getKey();
            }
        }
        return res;     
    }
}