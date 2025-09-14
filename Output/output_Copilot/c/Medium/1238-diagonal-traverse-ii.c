/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * 100000);
    *returnSize = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        max += numsColSize[i];
    }
    int *temp = (int *)malloc(sizeof(int) * max);
    int tempSize = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            temp[tempSize++] = nums[i][j];
        }
    }
    int **diagonals = (int **)malloc(sizeof(int *) * max);
    int *diagonalsColSize = (int *)malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++) {
        diagonals[i] = (int *)malloc(sizeof(int) * max);
    }
    int diagonalsSize = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            int row = i, col = j;
            while (diagonalsColSize[row + col] != 0) {
                row++;
                col--;
            }
            diagonalsColSize[row + col] = 1;
            diagonals[row + col][0]++;
            diagonals[row + col][diagonals[row + col][0]] = temp[i * 100 + j];
            if (row + col > diagonalsSize) {
                diagonalsSize = row + col;
            }
        }
    }
    for (int i = 0; i <= diagonalsSize; i++) {
        for (int j = 1; j <= diagonals[i][0]; j++) {
            result[(*returnSize)++] = diagonals[i][j];
        }
    }
    return result;    
}