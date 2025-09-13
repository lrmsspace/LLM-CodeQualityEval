/*
 You are given a 0-indexed integer array nums.
 The distinct count of a subarray of nums is defined as:
 Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
 Return the sum of the squares of distinct counts of all subarrays of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 A subarray is a contiguous non-empty sequence of elements within an array.
 Example 1:
 Input: nums = [1,2,1]
 Output: 15
 Explanation: Six possible subarrays are:
 [1]: 1 distinct value
 [2]: 1 distinct value
 [1]: 1 distinct value
 [1,2]: 2 distinct values
 [2,1]: 2 distinct values
 [1,2,1]: 2 distinct values
 The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
 Example 2:
 Input: nums = [2,2]
 Output: 3
 Explanation: Three possible subarrays are:
 [2]: 1 distinct value
 [2]: 1 distinct value
 [2,2]: 1 distinct value
 The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

int sumCounts(int* nums, int numsSize) {
    const int MOD = 1000000007;
    long long result = 0;
    int last[100001] = {0}; // Last occurrence of each number
    int distinctCount = 0; // Current distinct count
    int start = 0; // Start index of the current subarray

    for (int end = 0; end < numsSize; end++) {
        if (last[nums[end]] == 0) {
            distinctCount++;
        } else {
            // If the number has appeared before, we need to update the start index
            start = (start > last[nums[end]]) ? start : last[nums[end]];
        }
        last[nums[end]] = end + 1; // Store the next index where this number appears

        // Add the square of the current distinct count to the result
        result = (result + (long long)distinctCount * distinctCount) % MOD;
    }

    return (int)result;    
}