/*
 You are given an integer array nums of length n, and a positive integer k.
 The power of a subsequence is defined as the minimum absolute difference between any two elements in the subsequence.
 Return the sum of powers of all subsequences of nums which have length equal to k.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4], k = 3
 Output: 4
 Explanation:
 There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.
 Example 2:
 Input: nums = [2,2], k = 2
 Output: 0
 Explanation:
 The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.
 Example 3:
 Input: nums = [4,3,-1], k = 2
 Output: 10
 Explanation:
 There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.
 Constraints:
 2 <= n == nums.length <= 50
 -108 <= nums[i] <= 108 
 2 <= k <= n
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var sumOfPowers = function(nums, k) {
    const mod = 1e9 + 7;
    let totalPower = 0;

    const getSubsequencePower = (subseq) => {
        let minDiff = Infinity;
        for (let i = 0; i < subseq.length; i++) {
            for (let j = i + 1; j < subseq.length; j++) {
                minDiff = Math.min(minDiff, Math.abs(subseq[i] - subseq[j]));
            }
        }
        return minDiff;
    };

    const findSubsequences = (start, current) => {
        if (current.length === k) {
            totalPower = (totalPower + getSubsequencePower(current)) % mod;
            return;
        }
        for (let i = start; i < nums.length; i++) {
            findSubsequences(i + 1, [...current, nums[i]]);
        }
    };

    findSubsequences(0, []);
    return totalPower;
};