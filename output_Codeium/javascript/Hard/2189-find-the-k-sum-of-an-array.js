/**https://leetcode.com/problems/find-the-k-sum-of-an-array/ */
//You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
//We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
//Return the K-Sum of the array.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//Note that the empty subsequence is considered to have a sum of 0.
// 
//Example 1:
//Input: nums = [2,4,-2], k = 5
//Output: 2
//Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
//- 6, 4, 4, 2, 2, 0, 0, -2.
//The 5-Sum of the array is 2.
//Example 2:
//Input: nums = [1,-2,3,4,-10,12], k = 16
//Output: 10
//Explanation: The 16-Sum of the array is 10.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	-109 <= nums[i] <= 109
//	1 <= k <= min(2000, 2n)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var kSum = function(nums, k) {
    let n = nums.length;
    let prefixSums = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        prefixSums[i + 1] = prefixSums[i] + nums[i];
    }
    let queue = new PriorityQueue((a, b) => b[0] - a[0]);
    queue.push([0, 0]);
    let visited = new Set();
    while (queue.size > 0) {
        let [sum, left] = queue.shift();
        if (visited.has(`${sum},${left}`)) {
            continue;
        }
        visited.add(`${sum},${left}`);
        if (left === n) {
            if (k === 1) {
                return sum;
            }
            k--;
        } else {
            queue.push([sum + nums[left], left + 1]);
            queue.push([sum, left + 1]);
        }
    }
    return 0;
};