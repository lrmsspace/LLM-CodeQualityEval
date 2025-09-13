/**https://leetcode.com/problems/binary-tree-right-side-view/ */
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// 
//Example 1:
//Input: root = [1,2,3,null,5,null,4]
//Output: [1,3,4]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,null,null,null,5]
//Output: [1,3,4,5]
//Explanation:
//Example 3:
//Input: root = [1,null,3]
//Output: [1,3]
//Example 4:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 100].
//	-100 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    if(!root) return [];
    let queue = [root];
    let result = [];
    while(queue.length){
        let size = queue.length;
        for(let i=0;i<size;i++){
            let node = queue.shift();
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);
            if(i===size-1) result.push(node.val);
        }
    }
    return result;
};