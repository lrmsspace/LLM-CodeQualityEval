/**https://leetcode.com/problems/cousins-in-binary-tree-ii/ */
//Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
//Two nodes of a binary tree are cousins if they have the same depth with different parents.
//Return the root of the modified tree.
//Note that the depth of a node is the number of edges in the path from the root node to it.
// 
//Example 1:
//Input: root = [5,4,9,1,10,null,7]
//Output: [0,0,0,7,7,null,11]
//Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
//- Node with value 5 does not have any cousins so its sum is 0.
//- Node with value 4 does not have any cousins so its sum is 0.
//- Node with value 9 does not have any cousins so its sum is 0.
//- Node with value 1 has a cousin with value 7 so its sum is 7.
//- Node with value 10 has a cousin with value 7 so its sum is 7.
//- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
//Example 2:
//Input: root = [3,1,2]
//Output: [0,0,0]
//Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
//- Node with value 3 does not have any cousins so its sum is 0.
//- Node with value 1 does not have any cousins so its sum is 0.
//- Node with value 2 does not have any cousins so its sum is 0.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 105].
//	1 <= Node.val <= 104
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
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        root.val = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            int sum = 0;
            List<TreeNode> list = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                list.add(node);
                if (node.left != null) {
                    q.offer(node.left);
                    sum += node.left.val;
                }
                if (node.right != null) {
                    q.offer(node.right);
                    sum += node.right.val;
                }
            }
            for (TreeNode node : list) {
                int val = sum;
                if (node.left != null) {
                    val -= node.left.val;
                }
                if (node.right != null) {
                    val -= node.right.val;
                }
                if (node.left != null) {
                    node.left.val = val;
                }
                if (node.right != null) {
                    node.right.val = val;
                }
            }
        }
        return root;     
    }
}