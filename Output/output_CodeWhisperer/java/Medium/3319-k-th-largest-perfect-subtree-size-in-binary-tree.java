/*
 You are given the root of a binary tree and an integer k.
 Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
 A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
 Example 1:
 Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
 Output: 3
 Explanation:
 The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
 The 2nd largest size is 3.
 Example 2:
 Input: root = [1,2,3,4,5,6,7], k = 1
 Output: 7
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.
 Example 3:
 Input: root = [1,2,3,null,4], k = 3
 Output: -1
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.
 Constraints:
 The number of nodes in the tree is in the range [1, 2000].
 1 <= Node.val <= 2000
 1 <= k <= 1024
*/

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
    // Store perfect subtree sizes in descending order
    List<Integer> sizes = new ArrayList<>();
    
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        // Get height and check if perfect for each subtree
        dfs(root);
        
        // Sort sizes in descending order
        Collections.sort(sizes, Collections.reverseOrder());
        
        // Return kth largest size if exists, otherwise -1
        return k <= sizes.size() ? sizes.get(k-1) : -1;
    }
    
    // Returns height of subtree if it's perfect, 0 if not perfect
    private int dfs(TreeNode node) {
        if (node == null) {
            return 0;
        }
        
        int leftHeight = dfs(node.left);
        int rightHeight = dfs(node.right);
        
        // Check if current subtree is perfect
        if (leftHeight == rightHeight) {
            // Perfect subtree found - calculate size
            if (leftHeight > 0 || (node.left == null && node.right == null)) {
                int size = (1 << (leftHeight + 1)) - 1;
                sizes.add(size);
                return leftHeight + 1;
            }
        }
        
        return 0;
    }
}  