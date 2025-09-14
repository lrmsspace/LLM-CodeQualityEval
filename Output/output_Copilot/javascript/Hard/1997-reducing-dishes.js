/**https://leetcode.com/problems/reducing-dishes/ */
//A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
//Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
//Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
//Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
// 
//Example 1:
//Input: satisfaction = [-1,-8,0,5,-9]
//Output: 14
//Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
//Each dish is prepared in one unit of time.
//Example 2:
//Input: satisfaction = [4,3,2]
//Output: 20
//Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
//Example 3:
//Input: satisfaction = [-1,-4,-5]
//Output: 0
//Explanation: People do not like the dishes. No dish is prepared.
// 
//Constraints:
//	n == satisfaction.length
//	1 <= n <= 500
//	-1000 <= satisfaction[i] <= 1000
/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
    satisfaction.sort((a, b) => a - b); // Sort the satisfaction array in ascending order
    let maxSum = 0; // Initialize the maximum sum of like-time coefficients
    let currentSum = 0; // Initialize the current sum of like-time coefficients

    for (let i = satisfaction.length - 1; i >= 0; i--) { // Iterate from the end of the sorted array
        currentSum += satisfaction[i]; // Add the current satisfaction level to the current sum
        if (currentSum > 0) { // If the current sum is positive
            maxSum += currentSum; // Add it to the maximum sum
        } else {
            break; // If the current sum is not positive, break out of the loop
        }
    }

    return maxSum; // Return the maximum sum of like-time coefficients    
};