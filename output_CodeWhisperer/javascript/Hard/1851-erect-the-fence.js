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
    trees.sort((a, b) => a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
    let upper = [], lower = [];
    for (let i = 0; i < trees.length; i++) {
        while (upper.length >= 2 && cross(upper[upper.length - 2], upper[upper.length - 1], trees[i]) > 0) {
            upper.pop();
        }
        while (lower.length >= 2 && cross(lower[lower.length - 2], lower[lower.length - 1], trees[i]) < 0) {
            lower.pop();
        }
        upper.push(trees[i]);
        lower.push(trees[i]);
    }
    let res = new Set();
    for (let i = 0; i < upper.length; i++) {
        res.add(upper[i].toString());
    }
    for (let i = 0; i < lower.length; i++) {
        res.add(lower[i].toString());
    }
    return Array.from(res).map(s => s.split(',').map(Number));
 
};