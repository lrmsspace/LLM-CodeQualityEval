/**https://leetcode.com/problems/most-frequent-subtree-sum/ */
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// 
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
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
    public int[] findFrequentTreeSum(TreeNode root) {
        HashMap<Integer,Integer> map=new HashMap<>();
        int max=0;
        int[] ans=new int[]{};
        helper(root,map);
        for(int i:map.keySet()){
            if(map.get(i)>max){
                max=map.get(i);
                ans=new int[]{i};
            }
            else if(map.get(i)==max){
                int[] temp=new int[ans.length+1];
                for(int j=0;j<ans.length;j++){
                    temp[j]=ans[j];
                }
                temp[temp.length-1]=i;
            }
        }
        return ans;
    }
}