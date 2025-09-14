/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> res = new ArrayList<>();
        if (root == null || target == null || k < 0) {
            return res;
        }
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        dfs(root, null, parent);
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(target);
        Set<TreeNode> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (k == 0) {
                    res.add(node.val);
                }
                if (node.left != null && !visited.contains(node.left)) {
                    queue.offer(node.left);
                }
                if (node.right != null && !visited.contains(node.right)) {
                    queue.offer(node.right);
                }
                if (parent.get(node) != null && !visited.contains(parent.get(node))) {
                    queue.offer(parent.get(node));
                }
                visited.add(node);
            }
            k--;
        }
        return res;
        
    }
    
    private void dfs(TreeNode root, TreeNode parent, Map<TreeNode, TreeNode> map) {
        if (root == null) {
            return;
        }
        map.put(root, parent);
        dfs(root.left, root, map);
        dfs(root.right, root, map);
    }
    }
}