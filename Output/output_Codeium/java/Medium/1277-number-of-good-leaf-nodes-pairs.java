/**https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/ */
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.
// 
//Example 1:
//Input: root = [1,2,3,null,4], distance = 3
//Output: 1
//Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
//Example 2:
//Input: root = [1,2,3,4,5,6,7], distance = 3
//Output: 2
//Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
//Example 3:
//Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
//Output: 1
//Explanation: The only good pair is [2,5].
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 210].
//	1 <= Node.val <= 100
//	1 <= distance <= 10
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
    public int countPairs(TreeNode root, int distance) {
        if (root == null) return 0;

        int[] result = new int[1];
        countLeafPairs(root, distance, result);
        return result[0];
    }

    private int[] countLeafPairs(TreeNode node, int distance, int[] result) {
        if (node == null) return new int[distance + 1];

        if (node.left == null && node.right == null) {
            int[] leafCounts = new int[distance + 1];
            leafCounts[1] = 1;
            return leafCounts;
        }

        int[] leftCounts = countLeafPairs(node.left, distance, result);
        int[] rightCounts = countLeafPairs(node.right, distance, result);

        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance - i; j++) {
                result[0] += leftCounts[i] * rightCounts[j];
            }
        }

        int[] currentCounts = new int[distance + 1];
        for (int i = 2; i <= distance; i++) {
            currentCounts[i] = leftCounts[i - 1] + rightCounts[i - 1];
        }

        return currentCounts;

    }
}