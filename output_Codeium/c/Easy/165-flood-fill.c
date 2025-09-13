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
void dfs(int **ans, int x, int y, int oldColor, int newColor, int dx[], int dy[], int *imageColSize) {
    if (x < 0 || x >= sizeof(ans) / sizeof(int*) || y < 0 || y >= *imageColSize || ans[x][y] != oldColor) {
        return;
    }

    ans[x][y] = newColor;
    for (int i = 0; i < 4; ++i) {
        dfs(ans, x + dx[i], y + dy[i], oldColor, newColor, dx, dy, imageColSize);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int **ans = (int**)malloc(imageSize * sizeof(int*));
    for (int i = 0; i < imageSize; ++i) {
        ans[i] = (int*)malloc(*imageColSize * sizeof(int));
        for (int j = 0; j < *imageColSize; ++j) {
            ans[i][j] = image[i][j];
        }
    }

    int oldColor = image[sr][sc];
    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
        for (int i = 0; i < imageSize; ++i) {
            (*returnColumnSizes)[i] = *imageColSize;
        }
        return ans;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    dfs(ans, sr, sc, oldColor, color, dx, dy, imageColSize);

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; ++i) {
        (*returnColumnSizes)[i] = *imageColSize;
    }
    return ans;
}

