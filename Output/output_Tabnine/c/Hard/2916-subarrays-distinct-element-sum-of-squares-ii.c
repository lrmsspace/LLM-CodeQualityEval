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
    int MOD = 1000000007;
    int n = numsSize;
    int* count = (int*)malloc(sizeof(int) * n);
    int* prefix = (int*)malloc(sizeof(int) * n);
    int sum = 0;
    
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        count[i] = 1;
        for (int j = i; j < n; j++) {
            int diff = prefix[j] - (i > 0? prefix[i - 1] : 0);
            count[i] += diff > 0? diff : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        sum = (sum + (long)count[i] * count[i]) % MOD;
    }
    free(count);
    free(prefix);   
    return sum;
    
}