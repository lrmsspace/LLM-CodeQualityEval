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

    var min = Number.MAX_SAFE_INTEGER;
    var max = Number.MIN_SAFE_INTEGER;
    var start = 0;
    var end = 0;
    var result = [];
    var queue = [];
    var visited = [];
    var count = 0;
    var i = 0;
    var j = 0;
    var k = 0;
    var n = nums.length;
    var m = nums[0].length;
    var flag = false;
    
    for(i = 0; i < n; i++){
        queue.push([nums[i][0], i, 0]);
        visited[i] = false;
    }
    queue.sort(function(a, b){
        return a[0] - b[0];
    });
    while(true){
        var temp = queue.shift();
        var num = temp[0];
        var list = temp[1];
        var index = temp[2];
        if(num < min){
            min = num;
        }
        if(num > max){
            max = num;
        }
        if(max - min < result[1] - result[0]){
            result = [min, max];
        }
        if(index + 1 < m){
            queue.push([nums[list][index + 1], list, index + 1]);
            queue.sort(function(a, b){
                return a[0] - b[0];
            });
        }
    }
    return result;
};