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
class Solution {
    public int[] findMode(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        int max = 0;
        int cur = 0;
        TreeNode pre = null;
        while (root != null) {
            if (root.left == null) {
                if (pre != null && pre.val == root.val) {
                    cur++;
                } else {
                    cur = 1;
                }
                if (cur > max) {
                    max = cur;
                    list.clear();
                    list.add(root.val);
                } else if (cur == max) {
                    list.add(root.val);
                }
                pre = root;
                root = root.right;
            } else {
                TreeNode node = root.left;
                while (node.right != null && node.right != root) {
                    node = node.right;
                }
                if (node.right == null) {
                    node.right = root;
                    root = root.left;
                } else {
                    node.right = null;
                    if (pre != null && pre.val == root.val) {
                        cur++;
                    } else {
                        cur = 1;
                    }
                    if (cur > max) {
                        max = cur;
                        list.clear();
                        list.add(root.val);
                    } else if (cur == max) {
                        list.add(root.val);
                    }
                    pre = root;
                    root = root.right;
                }
            }
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}