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
    let k = nums.length;
    let n = nums[0].length;
    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    let res = [min, max];
    let heap = new MinPriorityQueue({ priority: (x) => x[0] });
    let maxVal = Number.MIN_SAFE_INTEGER;
    for (let i = 0; i < k; i++) {
        heap.enqueue([nums[i][0], i, 0]);
        maxVal = Math.max(maxVal, nums[i][0]);
    }
    while (true) {
        let [val, i, j] = heap.dequeue().element;
        if (maxVal - val < res[1] - res[0] || (maxVal - val == res[1] - res[0] && val < res[0])) {
            res = [val, maxVal];
        }
        if (j + 1 == n) {
            break;
        }
        heap.enqueue([nums[i][j + 1], i, j + 1]);
        maxVal = Math.max(maxVal, nums[i][j + 1]);
    }
    return res;
};