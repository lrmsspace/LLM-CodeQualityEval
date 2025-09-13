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
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 10000);
    int i = 0, j = 0, k = 0;
    while (i < numsSize) {
        int x = i, y = j;
        while (x >= 0 && y < numsColSize[i]) {
            res[k++] = nums[x][y];
            x--;
            y++;
       }
    }
    while (j < numsColSize[i - 1]) {
        int x = i - 1, y = j;
        while (x >= 0 && y < numsColSize[i - 1]) {
            res[k++] = nums[x][y];
            x--;
            y++;
        }
        j++;
    }
    *returnSize = k;
    return res;
}