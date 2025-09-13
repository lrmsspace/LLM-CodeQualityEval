/**https://leetcode.com/problems/trapping-rain-water-ii/ */
//Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
// 
//Example 1:
//Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
//Output: 4
//Explanation: After the rain, water is trapped between the blocks.
//We have two small ponds 1 and 3 units trapped.
//The total volume of water trapped is 4.
//Example 2:
//Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
//Output: 10
// 
//Constraints:
//	m == heightMap.length
//	n == heightMap[i].length
//	1 <= m, n <= 200
//	0 <= heightMap[i][j] <= 2 * 104
int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h,
        min, max, sum, count, average, result,
        row, col,
        *height, *height_row, *height_col, *height_row_col, *height_row_col_min, *height_row_col_max, *height_row_col_sum, *height_row_col_count, *height_row_col_average, *height_row_col_result;
        row = heightMapSize;
        col = heightMapColSize[0];
        height = (int *)malloc(sizeof(int) * row * col);
        height_row = (int *)malloc(sizeof(int) * row);
        height_col = (int *)malloc(sizeof(int) * col);
        height_row_col = (int *)malloc(sizeof(int) * row * col);
        height_row_col_min = (int *)malloc(sizeof(int) * row * col);
        height_row_col_max = (int *)malloc(sizeof(int) * row * col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                height_row[i] = heightMap[i][0];
                height_col[j] = heightMap[0][j];
                height_row_col[i * col + j] = heightMap[i][j];
                height_row_col_min[i * col + j]= heightMap[i][j];
            }
        }
        for (i = 1; i < row; i++) {
            for (j = 1; j < col; j++) {
                height_row[i] = MAX(height_row[i], heightMap[i][j]);
                height_col[j] = MAX(height_col[j], heightMap[i][j]);
                height_row_col[i * col + j] = MAX(height_row_col[i * col + j], heightMap[i][j]);
            }
        }
        for (i = 1; i < row; i++) {
            for (j = 1; j < col; j++) {
                res += MIN(MIN(height_row[i], height_col[j]), height_row_col[i * col + j]) - heightMap[i][j];
            }
        }
        return res;
}