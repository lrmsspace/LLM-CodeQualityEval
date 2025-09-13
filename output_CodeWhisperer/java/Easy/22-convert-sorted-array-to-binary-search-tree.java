/**https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ */
//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// 
//Example 1:
//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//Example 2:
//Input: nums = [1,3]
//Output: [3,1]
//Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
// 
//Constraints:
//	1 <= nums.length <= 104
//	-104 <= nums[i] <= 104
//	nums is sorted in a strictly increasing order.
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
public TreeNode sortedArrayToBST(int[] nums) {
    if (nums == null || nums.length == 0) {
        return null;
    }
    return buildBST(nums, 0, nums.length - 1);
}

private TreeNode buildBST(int[] nums, int left, int right) {
    if (left > right) {
        return null;
    }
    
    // Find the middle element to make it the root
    int mid = left + (right - left) / 2;
    
    // Create a new TreeNode with the middle element
    TreeNode root = new TreeNode(nums[mid]);
    
    // Recursively build left and right subtrees
    root.left = buildBST(nums, left, mid - 1);
    root.right = buildBST(nums, mid + 1, right);
    
    return root;
}
