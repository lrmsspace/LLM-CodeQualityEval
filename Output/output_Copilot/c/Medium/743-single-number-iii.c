/**https://leetcode.com/problems/single-number-iii/ */
//Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
// 
//Example 1:
//Input: nums = [1,2,1,3,2,5]
//Output: [3,5]
//Explanation:  [5, 3] is also a valid answer.
//Example 2:
//Input: nums = [-1,0]
//Output: [-1,0]
//Example 3:
//Input: nums = [0,1]
//Output: [1,0]
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-231 <= nums[i] <= 231 - 1
//	Each integer in nums will appear twice, only two integers will appear once.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int bitmask = 0;
    for (int i = 0; i < numsSize; i++) {
        bitmask ^= nums[i];
    }
    int diff = bitmask & (-bitmask);
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((diff & nums[i]) != 0) {
            x ^= nums[i];
        }
    }
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = x;
    ret[1] = bitmask ^ x;
    return ret;    
}