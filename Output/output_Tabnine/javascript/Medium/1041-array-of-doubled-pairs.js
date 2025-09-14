/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
// 
//Example 1:
//Input: arr = [3,1,3,6]
//Output: false
//Example 2:
//Input: arr = [2,1,2,6]
//Output: false
//Example 3:
//Input: arr = [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// 
//Constraints:
//	2 <= arr.length <= 3 * 104
//	arr.length is even.
//	-105 <= arr[i] <= 105
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canReorderDoubled = function(arr) {
    const count = arr.reduce((acc, val) => {
        acc[val] = (acc[val] || 0) + 1;
        return acc;
    }, {});
    
    const sorted = Object.entries(count).sort((a, b) => Math.abs(a[0]) - Math.abs(b[0]));
    
    for (let [num, freq] of sorted) {
        if (freq > Math.floor(num / 2)) return false;
        count[num] -= Math.floor(num / 2);
        count[num * 2] -= freq;
    }
    
    return Object.values(count).every(val => val === 0);
    
};