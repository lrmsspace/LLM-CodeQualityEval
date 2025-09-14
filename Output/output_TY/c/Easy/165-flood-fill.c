/**https://leetcode.com/problems/flood-fill/ */
//An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
//To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
//Return the modified image after performing the flood fill.
// 
//Example 1:
//Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
//Output: [[2,2,2],[2,2,0],[2,0,1]]
//Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
//Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
//Example 2:
//Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
//Output: [[0,0,0],[0,0,0]]
//Explanation: The starting pixel is already colored 0, so no changes are made to the image.
// 
//Constraints:
//	m == image.length
//	n == image[i].length
//	1 <= m, n <= 50
//	0 <= image[i][j], color < 216
//	0 <= sr < m
//	0 <= sc < n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    int* row = malloc(sizeof(int) * imageSize);
    int* col = malloc(sizeof(int) * imageSize);
    int* visited = malloc(sizeof(int) * imageSize);
    memset(visited, 0, sizeof(int) * imageSize);
    int* rowSize = malloc(sizeof(int) * imageSize);
    memset(rowSize, 0, sizeof(int) * imageSize);
    int* colSize = malloc(sizeof(int) * imageSize);
    memset(colSize, 0, sizeof(int) * imageSize);
    int rowIndex = 0;
    row[rowIndex] = sr;
    col[rowIndex] = sc;
    visited[rowIndex] = 1;
    while (rowIndex >= 0) {
        int curRow = row[rowIndex];
        int curCol = col[rowIndex];
        int curColor = image[curRow][curCol];
        if (curColor != color) {
            image[curRow][curCol] = color;
            rowSize[rowIndex]++;
        }
        int nextRow = curRow - 1;
        int nextCol = curCol;
        if (
            nextRow >= 0 &&
            nextRow < imageSize &&
            nextCol >= 0 &&
            nextCol < imageColSize[nextRow] &&
            image[nextRow][nextCol] == curColor &&
            visited[nextRow * imageColSize[nextRow] + nextCol] == 0
        ) {
            row[++rowIndex] = nextRow;
            col[rowIndex] = nextCol;
        }
    }
    *returnSize = rowIndex + 1;
    *returnColumnSizes = colSize;
    return row;
}