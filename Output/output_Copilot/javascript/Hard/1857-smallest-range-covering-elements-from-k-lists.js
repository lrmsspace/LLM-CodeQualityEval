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
    let minRange = [0, Infinity];
    let maxHeap = new MaxHeap();
    let minHeap = new MinHeap();
    let minVal = Infinity;
    let maxVal = -Infinity;
    
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums[i].length; j++) {
            maxHeap.insert(nums[i][j]);
            minHeap.insert(nums[i][j]);
            minVal = Math.min(minVal, nums[i][j]);
            maxVal = Math.max(maxVal, nums[i][j]);
        }
    }
    
    while (maxHeap.size() > 0 && minHeap.size() > 0) {
        let range = [minVal, maxHeap.peek()];
        if (range[1] - range[0] < minRange[1] - minRange[0]) {
            minRange = range;
        }
        
        if (maxHeap.peek() === maxVal) {
            break;
        }
        
        maxHeap.remove();
        minVal = Math.min(minVal, minHeap.peek());
    }
    
    return minRange;    
};