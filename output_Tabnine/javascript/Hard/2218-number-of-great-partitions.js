/**https://leetcode.com/problems/number-of-great-partitions/ */
//You are given an array nums consisting of positive integers and an integer k.
//Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.
//Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
//Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.
// 
//Example 1:
//Input: nums = [1,2,3,4], k = 4
//Output: 6
//Explanation: The great partitions are: ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], [1,2,3]).
//Example 2:
//Input: nums = [3,3,3], k = 4
//Output: 0
//Explanation: There are no great partitions for this array.
//Example 3:
//Input: nums = [6,6], k = 2
//Output: 2
//Explanation: We can either put nums[0] in the first partition or in the second partition.
//The great partitions will be ([6], [6]) and ([6], [6]).
// 
//Constraints:
//	1 <= nums.length, k <= 1000
//	1 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPartitions = function(nums, k) {
    // Count the frequency of each number
    let freq = Array(100001).fill(0);
    for (let num of nums) {
        freq[num]++;
    }
    
    // Initialize the prefix sum array and the count of partitions
    let prefixSum = Array(nums.length + 1).fill(0);
    let count = 0;
    
    // Iterate through the prefix sum array and calculate the number of partitions
    for (let i = 0; i <= nums.length; i++) {
        prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
        
        // If the sum of elements in the current partition is greater than or equal to k, increment the count
        if (prefixSum[i] >= k) {
            count += freq[prefixSum[i] - k];
        }
    }
    
    // Return the count modulo 10^9 + 7
    return count % (10 ** 9 + 7);
    
};