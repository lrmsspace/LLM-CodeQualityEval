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
    let map = new Map();
    for (let num of arr) {
        map.set(num, (map.get(num) || 0) + 1);
    }
    let keys = Array.from(map.keys()).sort((a, b) => Math.abs(a) - Math.abs(b));
    for (let key of keys) {
        if (map.get(key) > (map.get(key * 2) || 0)) {
            return false;
        }
        map.set(key * 2, (map.get(key * 2) || 0) - map.get(key));
    }
    return true;
};