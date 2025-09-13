/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */
//Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.
// 
//Example 1:
//Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//Output: [1,2,3,4,5,6,7]
//Example 2:
//Input: preorder = [1], postorder = [1]
//Output: [1]
// 
//Constraints:
//	1 <= preorder.length <= 30
//	1 <= preorder[i] <= preorder.length
//	All the values of preorder are unique.
//	postorder.length == preorder.length
//	1 <= postorder[i] <= postorder.length
//	All the values of postorder are unique.
//	It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        if (preorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[0]);
        if (preorder.length == 1) {
            return root;
        }
        int leftRoot = preorder[1];
        int leftRootIndex = 0;
        for (int i = 0; i < postorder.length; i++) {
            if (postorder[i] == leftRoot) {
                leftRootIndex = i;
                break;
            }
        }
        int[] leftPreorder = Arrays.copyOfRange(preorder, 1, leftRootIndex + 2);
        int[] leftPostorder = Arrays.copyOfRange(postorder, 0, leftRootIndex + 1);
        root.left = constructFromPrePost(leftPreorder, leftPostorder);
        int[] rightPreorder = Arrays.copyOfRange(preorder, leftRootIndex + 2, preorder.length);
        int[] rightPostorder = Arrays.copyOfRange(postorder, leftRootIndex + 1, postorder.length - 1);
        root.right = constructFromPrePost(rightPreorder, rightPostorder);
        return root;
        
    }
}