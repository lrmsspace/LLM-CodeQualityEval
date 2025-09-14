/*
 You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
 Return the minimum number of operations to make all elements of nums divisible by 3.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 3
 Explanation:
 All array elements can be made divisible by 3 using 3 operations:
 Subtract 1 from 1.
 Add 1 to 2.
 Subtract 1 from 4.
 Example 2:
 Input: nums = [3,6,9]
 Output: 0
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
*/

int minimumOperations(int* nums, int numsSize) {
    int sum = 0;
    int count[3] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        count[nums[i] % 3]++;
    }
    
    int minOperations = INT_MAX;
    
    for (int i = 0; i < 3; i++) {
        minOperations = min(minOperations, count[i] / 3 * 3 + count[i % 2] * 2);
    }
    
    return sum % 3 == 0? minOperations : minOperations + 3 - sum % 3;
    
}