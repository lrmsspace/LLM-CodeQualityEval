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
    // Count the frequency of each number in the array
    let countMap = new Map();
    for (let num of arr) {
        countMap.set(num, (countMap.get(num) || 0) + 1);
    }
    
    // Sort the countMap by value in descending order
    let sortedCount = [...countMap.entries()].sort((a, b) => b[1] - a[1]);
    
    // Initialize the number of unique integers and the total count
    let uniqueCount = countMap.size;
    let totalCount = uniqueCount;
    
    // Iterate through the sorted count array
    for (let [num, freq] of sortedCount) {
        // If the total count is less than k, remove the current number and its frequency
        if (totalCount < k) {
            totalCount += freq;
            uniqueCount--;
        } else {
            // If the total count is equal to k, remove the current number and its frequency
            k -= freq;
            totalCount -= freq;
            uniqueCount--;
        }
        
        // If k becomes 0, break the loop
        if (k === 0) {
            break;
        }
    }
    
    return uniqueCount;

    

};