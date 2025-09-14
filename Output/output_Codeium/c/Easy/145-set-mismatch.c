/**https://leetcode.com/problems/set-mismatch/ */
//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.
// 
//Example 1:
//Input: nums = [1,2,2,4]
//Output: [2,3]
//Example 2:
//Input: nums = [1,1]
//Output: [1,2]
// 
//Constraints:
//	2 <= nums.length <= 104
//	1 <= nums[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int count[numsSize+1];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int *result = (int*)malloc(2 * sizeof(int));
    for (int i = 1; i <= numsSize; i++) {
        if (count[i] == 2) {
            result[0] = i;
        } else if (count[i] == 0) {
            result[1] = i;
        }
    }
    *returnSize = 2;
    return result;
}