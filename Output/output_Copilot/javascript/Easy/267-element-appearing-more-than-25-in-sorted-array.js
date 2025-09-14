/**https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ */
//Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
// 
//Example 1:
//Input: arr = [1,2,2,6,6,6,6,7,10]
//Output: 6
//Example 2:
//Input: arr = [1,1]
//Output: 1
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 105
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let n = arr.length;
    let count = 1;
    let maxCount = Math.floor(n / 4);
    
    for (let i = 1; i < n; i++) {
        if (arr[i] === arr[i - 1]) {
            count++;
            if (count > maxCount) {
                return arr[i];
            }
        } else {
            count = 1;
        }
    }
    
    return -1; // This line should never be reached given the problem constraints    
};