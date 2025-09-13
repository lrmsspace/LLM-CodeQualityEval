/*
 You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:
 Replace each even number with 0.
 Replace each odd numbers with 1.
 Sort the modified array in non-decreasing order.
 Return the resulting array after performing these operations.
 Example 1:
 Input: nums = [4,3,2,1]
 Output: [0,0,1,1]
 Explanation:
 Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
 After sorting nums in non-descending order, nums = [0, 0, 1, 1].
 Example 2:
 Input: nums = [1,5,1,4,2]
 Output: [0,0,1,1,1]
 Explanation:
 Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
 After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 1000
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);
    int *temp = malloc(sizeof(int) * numsSize);
    int flag = 1;
    while(flag){
        flag = 0;
        memcpy(temp, nums, sizeof(int) * numsSize);
        for(int i = 1; i < numsSize - 1; i++){
            if(temp[i] < temp[i - 1] && temp[i] < temp[i + 1]){
                nums[i] = temp[i] + 1;
                flag = 1;
            }
            else if(temp[i] > temp[i - 1] && temp[i] > temp[i + 1]){
                nums[i] = temp[i] - 1;
                flag = 1;
            }
        }
    }
    memcpy(ans, nums, sizeof(int) * numsSize);
    *returnSize = numsSize;
    return ans;    
}