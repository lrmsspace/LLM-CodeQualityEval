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
    int sum = 0;
    int mod = 1000000007;
    for(int i = 0; i < numsSize; i++) {
        for(int j = i; j < numsSize; j++) {
            int distinct = 0;
            int hash[100001] = {0};
            for(int k = i; k <= j; k++) {
                if(hash[nums[k]] == 0) {
                    distinct++;
                    hash[nums[k]] = 1;
                }
            }
            sum = (sum + distinct * distinct) % mod;
        }
    }
    return sum;    
}