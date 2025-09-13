/**https://leetcode.com/problems/erect-the-fence/ */
//You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
//Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
//Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
// 
//Example 1:
//Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
//Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
//Example 2:
//Input: trees = [[1,2],[2,2],[4,2]]
//Output: [[4,2],[2,2],[1,2]]
//Explanation: The fence forms a line that passes through all the trees.
// 
//Constraints:
//	1 <= trees.length <= 3000
//	trees[i].length == 2
//	0 <= xi, yi <= 100
//	All the given positions are unique.
/**
 * @param {number[][]} trees
 * @return {number[][]}
 */
var outerTrees = function(trees) {
    // Sort the trees by their x-coordinate
    trees.sort((a, b) => a[0] - b[0]);
    
    let stack = [];
    for (let i = 0; i < trees.length; i++) {
        while (stack.length >= 2 && orientation(stack[stack.length - 2], stack[stack.length - 1], trees[i]) <= 0) {
            stack.pop();
        }
        stack.push(trees[i]);
    }
    
    // Reverse the stack and remove the first and last elements (which are the same)
    stack.reverse();
    stack.pop();
    
    // Sort the remaining trees by their y-coordinate
    stack.sort((a, b) => a[1] - b[1]);
    
    // Add the first and last trees again
    stack.unshift(stack[stack.length - 1]);
    stack.push(stack[0]);
    
    return stack;
    
};