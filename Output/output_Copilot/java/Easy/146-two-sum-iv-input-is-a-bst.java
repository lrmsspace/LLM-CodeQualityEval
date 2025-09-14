/**https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ */
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
// 
//Example 1:
//Input: root = [5,3,6,2,4,null,7], k = 9
//Output: true
//Example 2:
//Input: root = [5,3,6,2,4,null,7], k = 28
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-104 <= Node.val <= 104
//	root is guaranteed to be a valid binary search tree.
//	-105 <= k <= 105
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
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        inOrder(root, list);
        int left = 0, right = list.size() - 1;
        while (left < right) {
            int sum = list.get(left) + list.get(right);
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;        
    }
}