/**https://leetcode.com/problems/flipping-an-image/ */
//Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
//To flip an image horizontally means that each row of the image is reversed.
//	For example, flipping [1,1,0] horizontally results in [0,1,1].
//To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
//	For example, inverting [0,1,1] results in [1,0,0].
// 
//Example 1:
//Input: image = [[1,1,0],[1,0,1],[0,0,0]]
//Output: [[1,0,0],[0,1,0],[1,1,1]]
//Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
//Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
//Example 2:
//Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
//Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
//Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
//Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// 
//Constraints:
//	n == image.length
//	n == image[i].length
//	1 <= n <= 20
//	images[i][j] is either 0 or 1.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result
    int** result = (int**)malloc(imageSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    *returnSize = imageSize;

    for (int i = 0; i < imageSize; i++) {
        result[i] = (int*)malloc((*imageColSize) * sizeof(int));
        (*returnColumnSizes)[i] = *imageColSize;

        // Flip and invert each row
        for (int j = 0; j < *imageColSize; j++) {
            result[i][j] = 1 - image[i][*imageColSize - j - 1];
        }
    }

    return result;
}
