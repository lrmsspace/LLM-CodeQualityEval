/**https://leetcode.com/problems/image-smoother/ */
//An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
//Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
// 
//Example 1:
//Input: img = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[0,0,0],[0,0,0],[0,0,0]]
//Explanation:
//For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
//For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
//For the point (1,1): floor(8/9) = floor(0.88888889) = 0
//Example 2:
//Input: img = [[100,200,100],[200,50,200],[100,200,100]]
//Output: [[137,141,137],[141,138,141],[137,141,137]]
//Explanation:
//For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
//For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
//For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
// 
//Constraints:
//	m == img.length
//	n == img[i].length
//	1 <= m, n <= 200
//	0 <= img[i][j] <= 255
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imgSize;
    *returnColumnSizes = (int*)malloc(imgSize * sizeof(int));
    for (int i = 0; i < imgSize; i++) {
        (*returnColumnSizes)[i] = imgColSize[i];
    }
    int** result = (int**)malloc(imgSize * sizeof(int*));
    for (int i = 0; i < imgSize; i++) {
        result[i] = (int*)malloc(imgColSize[i] * sizeof(int));
        for (int j = 0; j < imgColSize[i]; j++) {
            int count = 1;
            int sum = img[i][j];
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int row = i + x;
                    int col = j + y;
                    if (row >= 0 && row < imgSize && col >= 0 && col < imgColSize[i]) {
                        sum += img[row][col];
                        count++;
                    }
                }
            }
            result[i][j] = sum / count;
        }
    }
    return result;
}