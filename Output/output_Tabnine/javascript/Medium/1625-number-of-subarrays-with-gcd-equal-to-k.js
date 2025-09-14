/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.
// 
//Example 1:
//Input: nums = [9,3,1,2,6,3], k = 3
//Output: 4
//Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//- [9,3,1,2,6,3]
//Example 2:
//Input: nums = [4], k = 7
//Output: 0
//Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i], k <= 109
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayGCD = function(nums, k) {
    const n = nums.length;
    const dp = Array(n + 1).fill(0);
    const primes = Array(1001).fill(true);
    primes[0] = primes[1] = false;
    for (let i = 2; i <= Math.sqrt(1000); i++) {
        if (primes[i]) {
            for (let j = i * i; j <= 1000; j += i) {
                primes[j] = false;
            }
        }
    }
    let ans = 0;
    let gcd = (a, b) => {
        if (b === 0) return a;
        return gcd(b, a % b);
    };
    for (let i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + primes[nums[i - 1]];
        for (let j = 1; j < i; j++) {
            const g = gcd(nums[j - 1], nums[i - 1]);
            if (g === k) {
                ans += dp[j - 1];
            }
        }
    }
    return ans;
    
};