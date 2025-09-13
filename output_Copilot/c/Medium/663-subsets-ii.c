/**https://leetcode.com/problems/subsets-ii/ */
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ret = (int **)malloc(sizeof(int *) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    ret[0] = (int *)malloc(sizeof(int) * 1);
    (*returnColumnSizes)[0] = 0;
    (*returnSize)++;
    if (numsSize == 0) {
        return ret;
    }
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    int arrSize = 0;
    int **temp = (int **)malloc(sizeof(int *) * 10000);
    int *tempSize = (int *)malloc(sizeof(int) * 10000);
    int tempNum = 0;
    for (int i = 0; i < numsSize; i++) {
        int tempSize = *returnSize;
        for (int j = 0; j < tempSize; j++) {
            int *tempArr = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[j] + 1));
            for (int k = 0; k < (*returnColumnSizes)[j]; k++) {
                tempArr[k] = ret[j][k];
            }
            tempArr[(*returnColumnSizes)[j]] = nums[i];
            temp[tempNum] = tempArr;
            tempSize[tempNum] = (*returnColumnSizes)[j] + 1;
            tempNum++;
        }
        for (int j = 0; j < tempNum; j++) {
            ret[*returnSize] = temp[j];
            (*returnColumnSizes)[*returnSize] = tempSize[j];
            (*returnSize)++;
        }
        tempNum = 0;
    }
    return ret;    
}