/**https://leetcode.com/problems/subtree-of-another-tree/ */
//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
//A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
// 
//Example 1:
//Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//Output: true
//Example 2:
//Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//Output: false
// 
//Constraints:
//	The number of nodes in the root tree is in the range [1, 2000].
//	The number of nodes in the subRoot tree is in the range [1, 1000].
//	-104 <= root.val <= 104
//	-104 <= subRoot.val <= 104
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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) {
    return dfs(root, subRoot);
    
    function dfs(node, subNode){
        if(!node) return false;
        if(node.val === subNode.val){
            return isSameTree(node, subNode) || dfs(node.left, subNode) || dfs(node.right, subNode);
        }
        return dfs(node.left, subNode) || dfs(node.right, subNode);
    }
    
    function isSameTree(node1, node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        return node1.val === node2.val &&isSameTree(node1.left, node2.left) && is
    }
};