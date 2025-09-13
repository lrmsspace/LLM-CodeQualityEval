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

    const count = {};
    for (const num of arr) {
        count[num] = (count[num] || 0) + 1; // Count occurrences of each number
    }
    const frequencies = Object.values(count).sort((a, b) => a - b); // Sort frequencies in ascending order
    let uniqueCount = frequencies.length; // Start with the total number of unique integers

    for (const freq of frequencies) {
        if (k >= freq) {
            k -= freq; // Remove this frequency from k
            uniqueCount--; // Decrease the count of unique integers
        } else {
            break; // No more removals possible
        }
    }

    return uniqueCount; // Return the remaining count of unique integers
    
};