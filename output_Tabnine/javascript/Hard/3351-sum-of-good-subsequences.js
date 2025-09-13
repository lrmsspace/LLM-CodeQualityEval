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

    // Create a map to store the frequency of each number
    const freqMap = new Map();
    for (let num of nums) {
        freqMap.set(num, (freqMap.get(num) || 0) + 1);
    }
    
    // Initialize variables
    let sum = 0;
    const mod = 1e9 + 7;
    
    // Iterate through each number
    for (let num of freqMap.keys()) {
        // Calculate the number of good subsequences ending with the current number
        let count = 0;
        for (let i = 1; i <= num; i++) {
            count += freqMap.get(i) * freqMap.get(num - i);
        }
        
        // Add the count to the sum
        sum = (sum + count) % mod;
    }
    
    return sum;
    
};