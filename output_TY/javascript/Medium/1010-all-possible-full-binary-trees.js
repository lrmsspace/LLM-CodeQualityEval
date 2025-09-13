/**https://leetcode.com/problems/all-possible-full-binary-trees/ */
//Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
//Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
//A full binary tree is a binary tree where each node has exactly 0 or 2 children.
// 
//Example 1:
//Input: n = 7
//Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//Example 2:
//Input: n = 3
//Output: [[0,0,0]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var allPossibleFBT = function(n) {
    if(n%2===0) return [];
    if(n===1) return [new TreeNode(0)];
    let ans=[];
    for(let i=1;i<n;i+=2){
        let left=allPossibleFBT(i);
        let right=allPossibleFBT(n-i-1);
        for(let l of left){
            for(let r of right){
                let root=new TreeNode(0);
                root.left=l;
                root.right=r;
                ans.push(root);
            }
        }
    }
    return ans; 
};