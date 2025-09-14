/**https://leetcode.com/problems/tallest-billboard/ */
//You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
//You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
//Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
// 
//Example 1:
//Input: rods = [1,2,3,6]
//Output: 6
//Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
//Example 2:
//Input: rods = [1,2,3,4,5,6]
//Output: 10
//Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
//Example 3:
//Input: rods = [1,2]
//Output: 0
//Explanation: The billboard cannot be supported, so we return 0.
// 
//Constraints:
//	1 <= rods.length <= 20
//	1 <= rods[i] <= 1000
//	sum(rods[i]) <= 5000
/**
 * @param {number[]} rods
 * @return {number}
 */
var tallestBillboard = function(rods) {
    // Sort the rods in descending order
    rods.sort((a, b) => b - a);
    
    // Initialize the two subsets and their sums
    let subset1 = [];
    let subset2 = [];
    let sum1 = 0;
    let sum2 = 0;
    
    // Iterate through the rods and assign them to either subset
    for (let rod of rods) {
        // If the sum of subset1 is greater than or equal to subset2, add the rod to subset1
        if (sum1 >= sum2) {
            subset1.push(rod);
            sum1 += rod;
        } else { // Otherwise, add the rod to subset2
            subset2.push(rod);
            sum2 += rod;
        }
    }
    
    // Return the maximum height of the billboard installation
    return Math.max(sum1, sum2);
    
};