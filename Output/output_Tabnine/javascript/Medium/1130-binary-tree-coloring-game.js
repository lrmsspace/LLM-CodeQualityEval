/**https://leetcode.com/problems/binary-tree-coloring-game/ */
//Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.
//Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.
//Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)
//If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.
//You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
//Output: true
//Explanation: The second player can choose the node with value 2.
//Example 2:
//Input: root = [1,2,3], n = 3, x = 1
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is n.
//	1 <= x <= n <= 100
//	n is odd.
//	1 <= Node.val <= n
//	All the values of the tree are unique.
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
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */
var btreeGameWinningMove = function(root, n, x) {
    // Function to count the number of nodes of a given color
    function countNodes(node, color) {
        if (node === null) return 0;
        if (node.val === color) return 1 + countNodes(node.left, color) + countNodes(node.right, color);
        return countNodes(node.left, color) + countNodes(node.right, color);
    }
    
    // Function to get the maximum number of nodes of a given color
    function getMaxNodes(node, color) {
        if (node === null) return 0;
        if (node.val === color) return countNodes(node, color);
        return Math.max(getMaxNodes(node.left, color), getMaxNodes(node.right, color));
    }
    
    // Recursive function to check if the second player can win
    function checkWin(node, color) {
        if (node === null) return false;
        
        // Count the number of nodes of the other color
        let otherColor = color === 1? 2 : 1;
        let otherCount = countNodes(node, otherColor);
        
        // Check if the second player can win by choosing a node with more than half of the other color nodes
        if (getMaxNodes(node, color) > Math.floor(otherCount / 2)) return true;
        
        // Recursively check the neighbors
        return checkWin(node.left, color) || checkWin(node.right, color) || checkWin(node.parent, color);
    }
    
    // Find the root node
    let rootNode = root;
    while (rootNode.parent!== null) rootNode = rootNode.parent;
    
    // Check if the second player can win
    return checkWin(rootNode, x);
    
};