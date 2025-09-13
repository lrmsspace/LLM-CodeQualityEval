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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** outerTrees(int** trees, int treesSize, int* treesColSize, int* returnSize, int** returnColumnSizes) {
    int n = treesSize;
    int res[n];
    int idx = 0, start = 0;
    while (idx < n) {
        int cur = start;
        for (int i = 0; i < n; ++i) {
            if (i != start && cross(trees[start], trees[i], trees[cur]) > 0)
                cur = i;
        }
        res[idx++] = cur;
        start = cur;
    }
    *returnSize = idx;
    *returnColumnSizes = (int*)malloc(sizeof(int) * idx);
    for (int i = 0; i < idx; ++i)
        (*returnColumnSizes)[i] = 2;
    int** resptr = (int**)malloc(sizeof(int*) * idx);
    for (int i = 0; i < idx; ++i)
        resptr[i] = trees[res[i]];
    return resptr;
}