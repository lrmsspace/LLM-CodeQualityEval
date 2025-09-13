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
    if (trees.length === 1) return trees;
    
    let convexHull = [];
    let leftMost = 0;
    for (let i = 1; i < trees.length; i++) {
        if (trees[i][0] < trees[leftMost][0]) {
            leftMost = i;
        }
    }

    let p = leftMost;
    let q;
    do {
        convexHull.push(trees[p]);
        q = (p + 1) % trees.length;
        for (let i = 0; i < trees.length; i++) {
            if (orientation(trees[p], trees[i], trees[q]) < 0) {
                q = i;
            }
        }
        p = q;
    } while (p !== leftMost);

    return convexHull;
    
    function orientation(p, q, r) {
        const val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
        if (val === 0) return 0;
        return val > 0 ? 1 : 2;
    }
};