/*
 You are given an array nums, where each number in the array appears either once or twice.
 Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.
 Example 1:
 Input: nums = [1,2,1,3]
 Output: 1
 Explanation:
 The only number that appears twice in nums is 1.
 Example 2:
 Input: nums = [1,2,3]
 Output: 0
 Explanation:
 No number appears twice in nums.
 Example 3:
 Input: nums = [1,2,2,1]
 Output: 3
 Explanation:
 Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
 Each number in nums appears either once or twice.
*/

int duplicateNumbersXOR(int* nums, int numsSize) {
    int xorResult = 0; // Initialize the result to 0

    for (int i = 0; i < numsSize; i++) {
        // XOR the number with itself if it appears twice
        xorResult ^= nums[i];
    }

    // If a number appears twice, it will cancel itself out in XOR
    // So we need to check if the result is 0 or not
    return xorResult;
    
}