/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **res = (int**)malloc(sizeof(int*) * 20000);
    int *temp = (int*)malloc(sizeof(int) * 20000);
    int resSize = 0;
    int tempSize = 0;
    int i, j, k;
    int last = -101;
    for (i = 0; i < (1 << numsSize); i++) {
        tempSize = 0;
        for (j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                if (nums[j] >= last) {
                    temp[tempSize++] = nums[j];
                    last = nums[j];
                }
            }
        }
        if (tempSize >= 2) {
            res[resSize] = (int*)malloc(sizeof(int) * tempSize);
            returnColumnSizes[0][resSize] = tempSize;
            for (k = 0; k < tempSize; k++) {
                res[resSize][k] = temp[k];
            }
            resSize++;
        }
        last = -101;
    }
    *returnSize = resSize;
    return res;    
}