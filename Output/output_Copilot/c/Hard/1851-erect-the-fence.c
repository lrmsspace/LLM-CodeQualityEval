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
//Explanation: The fence forms a line that passes through    all the trees.
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
int compare(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if (p1[0] == p2[0]) return p1[1] - p2[1];
    return p1[0] - p2[0];
}

int crossProduct(int* p, int* q, int* r) {
    return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
}

int** outerTrees(int** trees, int treesSize, int* treesColSize, int* returnSize, int** returnColumnSizes) {
    if (treesSize <= 3) {
        *returnSize = treesSize;
        *returnColumnSizes = malloc(treesSize * sizeof(int));
        for (int i = 0; i < treesSize; i++) {
            (*returnColumnSizes)[i] = 2;
        }
        return trees;
    }

    qsort(trees, treesSize, sizeof(int*), compare);

    int** hull = malloc(treesSize * 2 * sizeof(int*));
    int hullSize = 0;

    // Build lower hull
    for (int i = 0; i < treesSize; i++) {
        while (hullSize >= 2 && crossProduct(hull[hullSize - 2], hull[hullSize - 1], trees[i]) < 0) {
            hullSize--;
        }
        hull[hullSize++] = trees[i];
    }

    // Build upper hull
    int t = hullSize + 1;
    for (int i = treesSize - 1; i >= 0; i--) {
        while (hullSize >= t && crossProduct(hull[hullSize - 2], hull[hullSize - 1], trees[i]) < 0) {
            hullSize--;
        }
        hull[hullSize++] = trees[i];
    }

    // Remove duplicates
    int** result = malloc(hullSize * sizeof(int*));
    int resultSize = 0;
    int* seen = calloc(101 * 101, sizeof(int)); // Since 0 <= xi, yi <= 100
    for (int i = 0; i < hullSize; i++) {
        int x = hull[i][0], y = hull[i][1];
        if (!seen[x * 101 + y]) {
            result[resultSize++] = hull[i];
            seen[x * 101 + y] = 1;
        }
    }

    free(seen);
    free(hull);

    *returnSize = resultSize;
    *returnColumnSizes = malloc(resultSize * sizeof(int));
    for (int i = 0; i < resultSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
        
}