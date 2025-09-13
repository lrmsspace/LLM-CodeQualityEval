/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*2);
    int* cnt = (int*)calloc(sizeof(int), 2);
    int* hash = (int*)calloc(sizeof(int), 2);
    int i, j;
    for(i = 0; i < numsSize; i++){
        for(j = 0; j < 2; j++){
            if(nums[i] == ans[j]){
                hash[j]++;
                cnt[j]++;
            }
        }
    }
    for(i = 0; i < 2; i++){
        if(cnt[i] <= numsSize/3){
            ans[i] = -1;
        }
    }
    *returnSize = 2;
}