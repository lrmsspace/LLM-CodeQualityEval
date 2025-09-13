/**https://leetcode.com/problems/flood-fill/ */
//You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
//To perform a flood fill:
//	Begin with the starting pixel and change its color to color.
//	Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
//	Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
//	The process stops when there are no more adjacent pixels of the original color to update.
//Return the modified image after performing the flood fill.
// 
//Example 1:
//Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
//Output: [[2,2,2],[2,2,0],[2,0,1]]
//Explanation:
//From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
//Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.
//Example 2:
//Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
//Output: [[0,0,0],[0,0,0]]
//Explanation:
//The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
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
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize, n = *imageColSize;
    int oldColor = image[sr][sc];
    if (oldColor == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }
    int** res = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            res[i][j] = image[i][j];
        }
    }
    *returnSize = m;
    int dir[5] = {0, 1, 0, -1, 0};
    int* queue = (int*)malloc(sizeof(int) * m * n * 2);
    int front = 0, rear = 0;
    queue[rear++] = sr;
    queue[rear++] = sc;
    res[sr][sc] = color;
    while (front < rear) {
        int x = queue[front++];
        int y = queue[front++];
        for (int i = 0; i < 4; i++) {
            int tx = x + dir[i];
            int ty = y + dir[i + 1];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && res[tx][ty] == oldColor) {
                queue[rear++] = tx;
                queue[rear++] = ty;
                res[tx][ty] = color;
            }
        }
    }
    free(queue);
    return res;    
}