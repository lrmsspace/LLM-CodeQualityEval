/**https://leetcode.com/problems/left-and-right-sum-differences/ */
//Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:
//    answer.length == nums.length.
//    answer[i] = |leftSum[i] - rightSum[i]|.
//Where:
//    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
//    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
//Return the array answer.
// 
//Example 1:
//Input: nums = [10,4,8,3]
//Output: [15,1,11,22]
//Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
//The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
//Example 2:
//Input: nums = [1]
//Output: [0]
//Explanation: The array leftSum is [0] and the array rightSum is [0].
//The array answer is [|0 - 0|] = [0].
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int* leftSum = (int*)malloc(sizeof(int) * numsSize);
    int* rightSum = (int*)malloc(sizeof(int) * numsSize);
    leftSum[0] = 0;
    rightSum[numsSize - 1] = 0;
    for (int i = 1; i < numsSize; i++) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    for (int i = numsSize - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < numsSize; i++) {
        answer[i] = abs(leftSum[i] - rightSum[i]);
    }
    return answer;
    
}