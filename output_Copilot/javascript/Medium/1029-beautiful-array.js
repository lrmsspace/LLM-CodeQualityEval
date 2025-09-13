/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//	nums is a permutation of the integers in the range [1, n].
//	For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
// 
//Example 1:
//Input: n = 4
//Output: [2,1,4,3]
//Example 2:
//Input: n = 5
//Output: [3,1,2,5,4]
// 
//Constraints:
//	1 <= n <= 1000
/**
 * @param {number} n
 * @return {number[]}
 */
var beautifulArray = function(n) {
    let ans = [1]; // Initialize the answer array with the first element as 1
    while (ans.length < n) { // While the length of the answer array is less than n
        let temp = []; // Temporary array to store the next elements
        for (let i of ans) { // Iterate through each element in the current answer array
            if (i * 2 - 1 <= n) { // If the odd number can be added to the array
                temp.push(i * 2 - 1); // Add the odd number to the temporary array
            }
        }
        for (let i of ans) { // Iterate through each element in the current answer array again
            if (i * 2 <= n) { // If the even number can be added to the array
                temp.push(i * 2); // Add the even number to the temporary array
            }
        }
        ans = temp; // Update the answer array with the new temporary array
    }
    return ans; // Return the final answer array    
};