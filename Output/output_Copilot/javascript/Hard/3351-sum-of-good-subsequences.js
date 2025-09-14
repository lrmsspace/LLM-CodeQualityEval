/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfGoodSubsequences = function(nums) {
    const mod = 1e9 + 7;
    const n = nums.length;

    // Helper function to calculate the sum of good subsequences
    const calculateGoodSubsequenceSum = (start, end) => {
        let sum = 0;
        for (let i = start; i <= end; i++) {
            sum = (sum + nums[i]) % mod;
        }
        return sum;
    };

    let totalSum = 0;

    // Iterate through all possible subsequences
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            // Check if the subsequence is good
            if (Math.abs(nums[j] - nums[j - 1]) === 1) {
                totalSum = (totalSum + calculateGoodSubsequenceSum(i, j)) % mod;
            }
        }
    }

    return totalSum;
};