/**https://leetcode.com/problems/max-chunks-to-make-sorted-ii/ */
//You are given an integer array arr.
//We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
//Return the largest number of chunks we can make to sort the array.
// 
//Example 1:
//Input: arr = [5,4,3,2,1]
//Output: 1
//Explanation:
//Splitting into two or more chunks will not return the required result.
//For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
//Example 2:
//Input: arr = [2,1,3,4,4]
//Output: 4
//Explanation:
//We can split into two chunks, such as [2, 1], [3, 4, 4].
//However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
// 
//Constraints:
//	1 <= arr.length <= 2000
//	0 <= arr[i] <= 108
/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    const n = arr.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    
    // Build left array
    for (let i = 0, max = arr[0]; i < n; i++) {
        max = Math.max(max, arr[i]);
        left[i] = max;
    }
    
    // Build right array
    for (let i = n - 1, min = arr[n - 1]; i >= 0; i--) {
        min = Math.min(min, arr[i]);
        right[i] = min;
    }
    
    let count = 0;
    for (let i = 0; i < n - 1; i++) {
        if (left[i] <= right[i + 1]) {
            count++;
        }
    }
    
    return count + 1;
    
};