/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.
// 
//Example 1:
//Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//Output: [1,2,-3]
//Explanation: [1,2,-3] is able to achieve the given subset sums:
//- []: sum is 0
//- [1]: sum is 1
//- [2]: sum is 2
//- [1,2]: sum is 3
//- [-3]: sum is -3
//- [1,-3]: sum is -2
//- [2,-3]: sum is -1
//- [1,2,-3]: sum is 0
//Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
//Example 2:
//Input: n = 2, sums = [0,0,0,0]
//Output: [0,0]
//Explanation: The only correct answer is [0,0].
//Example 3:
//Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
//Output: [0,-1,4,5]
//Explanation: [0,-1,4,5] is able to achieve the given subset sums.
// 
//Constraints:
//	1 <= n <= 15
//	sums.length == 2n
//	-104 <= sums[i] <= 104
/**
 * @param {number} n
 * @param {number[]} sums
 * @return {number[]}
 */
var recoverArray = function(n, sums) {
    sums.sort((a, b) => a - b); // Sort the sums array in ascending order
    const ans = []; // Array to store the result
    const set = new Set(sums); // Use a set for O(1) lookups

    // Helper function to find the original array
    function findArray(n, sums, set) {
        if (n === 0) return []; // Base case: if n is 0, return an empty array
        const min = Math.min(...sums); // Find the minimum sum
        const max = Math.max(...sums); // Find the maximum sum
        const diff = max - min; // Calculate the difference between max and min

        // Check if the difference is even
        if (diff % 2 !== 0) return null; // If not, return null

        const target = (max + min) / 2; // Calculate the target value
        const newSums = new Set(); // Create a new set for the next level of recursion

        for (const sum of sums) {
            if (set.has(sum)) {
                newSums.add(sum + target); // Add target to each sum
                newSums.add(sum - target); // Subtract target from each sum
            }
        }

        const result = findArray(n - 1, Array.from(newSums), newSums); // Recursive call
        if (result === null) return null; // If no result, return null

        ans.push(target); // Add target to the result array
        return result; // Return the result
    }

    findArray(n, sums, set); // Start the recursive process
    return ans; // Return the final result    
};