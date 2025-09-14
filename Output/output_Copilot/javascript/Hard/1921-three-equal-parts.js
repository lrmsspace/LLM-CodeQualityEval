/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//	arr[0], arr[1], ..., arr[i] is the first part,
//	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//	All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
// 
//Example 1:
//Input: arr = [1,0,1,0,1]
//Output: [0,3]
//Example 2:
//Input: arr = [1,1,0,1,1]
//Output: [-1,-1]
//Example 3:
//Input: arr = [1,1,0,0,1]
//Output: [0,2]
// 
//Constraints:
//	3 <= arr.length <= 3 * 104
//	arr[i] is 0 or 1
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function(arr) {
    let n = arr.length, ones = 0, i = 0, j = n - 1;
    for (let k = 0; k < n; k++) {
        if (arr[k] === 1) ones++;
    }
    if (ones % 3 !== 0) return [-1, -1];
    if (ones === 0) return [0, n - 1];
    let p1 = Math.floor(ones / 3), p2 = Math.floor(2 * ones / 3);
    while (i < n && arr[i] !== 1) i++;
    while (j >= 0 && arr[j] !== 1) j--;
    let count1 = 0, count2 = 0;
    while (count1 < p1 && i < n) {
        if (arr[i] === 1) count1++;
        i++;
    }
    while (count2 < p2 && j >= 0) {
        if (arr[j] === 1) count2++;
        j--;
    }
    while (i < n && j >= 0 && arr[i] === arr[j]) {
        i++;
        j--;
    }
    return i > j ? [i - 1, j + 1] : [-1, -1];    
};