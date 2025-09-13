/**https://leetcode.com/problems/maximum-of-absolute-value-expression/ */
//Given two arrays of integers with equal lengths, return the maximum value of:
//|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
//where the maximum is taken over all 0 <= i, j < arr1.length.
// 
//Example 1:
//Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
//Output: 13
//Example 2:
//Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
//Output: 20
// 
//Constraints:
//	2 <= arr1.length == arr2.length <= 40000
//	-10^6 <= arr1[i], arr2[i] <= 10^6
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var maxAbsValExpr = function(arr1, arr2) {
    let n = arr1.length;
    let maxVal = 0;
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let diff1 = Math.abs(arr1[i] - arr1[j]);
            let diff2 = Math.abs(arr2[i] - arr2[j]);
            let diff3 = Math.abs(i - j);
            maxVal = Math.max(maxVal, diff1 + diff2 + diff3);
        }
    }
    
    return maxVal;
    
};