/**https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ */
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
// 
//Example 1:
//Input: arr = [5,5,4], k = 1
//Output: 1
//Explanation: Remove the single 4, only 5 is left.
//Example 2:
//Input: arr = [4,3,1,1,3,3,2], k = 3
//Output: 2
//Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
// 
//Constraints:
//	1 <= arr.length <= 10^5
//	1 <= arr[i] <= 10^9
//	0 <= k <= arr.length
/**

 * @param {number[]} arr

 * @param {number} k

 * @return {number}

 */

var findLeastNumOfUniqueInts = function(arr, k) {

    
    const counter = {};
    for (let num of arr) {
        counter[num] = counter[num] + 1 || 1;
    }
    const sorted = Object.entries(counter).sort((a, b) => a[1] - b[1]);
    let removed = 0;
    let i = 0;
    while (removed < k) {
        removed += sorted[i][1];
        i++;
    }
    return i;
};