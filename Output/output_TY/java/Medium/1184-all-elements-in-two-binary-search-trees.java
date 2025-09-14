/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
// 
//Example 1:
//Input: root1 = [2,1,4], root2 = [1,0,3]
//Output: [0,1,1,2,3,4]
//Example 2:
//Input: root1 = [1,null,8], root2 = [8,1]
//Output: [1,1,8,8]
// 
//Constraints:
//	The number of nodes in each tree is in the range [0, 5000].
//	-105 <= Node.val <= 105
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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> l1=new ArrayList<>();
        List<Integer> l2=new ArrayList<>();
        dfs(root1,l1);
        dfs(root2,l2);
        List<Integer> ans=new ArrayList<>();
        int i=0,j=0;
        while(i<l1.size() && j<l2.size())
        {
            if(l1.get(i)<l2.get(j))
            {
                ans.add(l1.get(i));
                i++;
            }
            else
            {
                ans.add(l2.get(j));
                j++;
            }
        }
        while(i<l1.size())
        {
            ans.add(l1.get(i));
            i++;
        }
        while(j<l2.size())
        {
            ans.add(l2.get(j));
            j++;
        }
        return ans;
    }
}