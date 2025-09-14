/**https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/ */
//Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
//Return the length of the shortest subarray to remove.
//A subarray is a contiguous subsequence of the array.
// 
//Example 1:
//Input: arr = [1,2,3,10,4,2,3,5]
//Output: 3
//Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
//Another correct solution is to remove the subarray [3,10,4].
//Example 2:
//Input: arr = [5,4,3,2,1]
//Output: 4
//Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
//Example 3:
//Input: arr = [1,2,3]
//Output: 0
//Explanation: The array is already non-decreasing. We do not need to remove any elements.
// 
//Constraints:
//	1 <= arr.length <= 105
//	0 <= arr[i] <= 109
/**
 * @param {number[]} arr
 * @return {number}
 */
var findLengthOfShortestSubarray = function(arr) {
    
    let left = 0;
    let right = arr.length - 1;
    
    while(left < right && arr[left] <= arr[right]) {
        left++;
    }
    
    if(left === right) return 0;
    
    let result = Math.min(arr.length - left - 1, right);
    
    let leftBound = 0;
    
    for(let i = 0; i < right; i++) {
        if(arr[i] <= arr[right]) {
            leftBound = i;
            result = Math.min(result, right - leftBound - 1);
        }
    }
    
   let rightBound = arr.length - 1;
    
 for(let i = right; i > left; i--) {
     if(arr[i] >= arr[left]) {
         rightBound = i;
         result = Math.min(result, rightBound - left - 1);
     }
 }
 return result;
};