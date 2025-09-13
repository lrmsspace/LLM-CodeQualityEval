/**https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/ */
//You are given an m x n integer matrix grid​​​.
//A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
//Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
//Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
// 
//Example 1:
//Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
//Output: [228,216,211]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 20 + 3 + 200 + 5 = 228
//- Red: 200 + 2 + 10 + 4 = 216
//- Green: 5 + 200 + 4 + 2 = 211
//Example 2:
//Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [20,9,8]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 4 + 2 + 6 + 8 = 20
//- Red: 9 (area 0 rhombus in the bottom right corner)
//- Green: 8 (area 0 rhombus in the bottom middle)
//Example 3:
//Input: grid = [[7,7,7]]
//Output: [7]
//Explanation: All three possible rhombus sums are the same, so return [7].
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 3);
    *returnSize = 0;
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int k = 0;
            while (i - k >= 0 && i + k < m && j - k >= 0 && j + k < n) {
                int sum = 0;
                for (int l = 0; l <= k; l++) {
                    sum += grid[i - l][j - k + l];
                    sum += grid[i + l][j - k + l];
                    sum += grid[i - l][j + k - l];
                    sum += grid[i + l][j + k - l];
                }
                sum -= grid[i - k][j - k];
                sum -= grid[i - k][j + k];
                sum -= grid[i + k][j - k];
                sum -= grid[i + k][j + k];
                k++;
                if (*returnSize < 3) {
                    result[*returnSize] = sum;
                    (*returnSize)++;
                    if (*returnSize == 3) {
                        qsort(result, 3, sizeof(int), cmp);
                    }
                } else {
                    if (sum > result[0]) {
                        if (sum == result[2]) {
                            continue;
                        }
                        if (sum == result[1]) {
                            result[0] = sum;
                            continue;
                        }
                        result[0] = sum;
                        qsort(result, 3, sizeof(int), cmp);
                    }
                }
            }
        }
    }
    return result;
}