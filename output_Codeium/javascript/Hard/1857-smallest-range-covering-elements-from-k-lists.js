/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var smallestRange = function(nums) {
    let pq = [];
    let maxNum = -Infinity;
    let range = Infinity;
    let result = [];

    for (let i = 0; i < nums.length; i++) {
        pq.push([nums[i][0], i, 0]);
        maxNum = Math.max(maxNum, nums[i][0]);
    }

    while (pq.length > 0) {
        let minNum = pq[0][0];
        let idx = pq[0][1];
        let k = pq[0][2];
        pq.shift();

        let newRange = maxNum - minNum;
        if (newRange < range) {
            range = newRange;
            result = [minNum, maxNum];
        }

        if (k + 1 < nums[idx].length) {
            pq.push([nums[idx][k + 1], idx, k + 1]);
            maxNum = Math.max(maxNum, nums[idx][k + 1]);
        }
    }

    return result;
};