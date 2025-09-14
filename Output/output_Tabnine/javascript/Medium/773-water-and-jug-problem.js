/**https://leetcode.com/problems/water-and-jug-problem/ */
//You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using the following operations:
//	Fill either jug completely with water.
//	Completely empty either jug.
//	Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.
// 
//Example 1: 
//Input:   x = 3, y = 5, target = 4 
//Output:   true 
//Explanation:
//Follow these steps to reach a total of 4 liters:
//	Fill the 5-liter jug (0, 5).
//	Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
//	Empty the 3-liter jug (0, 2).
//	Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).
//	Fill the 5-liter jug again (2, 5).
//	Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).
//	Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).
//Reference: The Die Hard example.
//Example 2: 
//Input:   x = 2, y = 6, target = 5 
//Output:   false 
//Example 3: 
//Input:   x = 1, y = 2, target = 3 
//Output:   true 
//Explanation: Fill both jugs. The total amount of water in both jugs is equal to 3 now.
// 
//Constraints:
//	1 <= x, y, target <= 103
/**
 * @param {number} x
 * @param {number} y
 * @param {number} target
 * @return {boolean}
 */
var canMeasureWater = function(x, y, target) {
    // Baby's first steps to solve this problem
    // Using three variables to represent the current states of the two jugs
    // jug1: the amount of water in the first jug
    // jug2: the amount of water in the second jug
    // total: the sum of the water in both jugs
    // We need to find a state where the total amount of water equals to the target
    
    // We use bit manipulation to represent the three variables
    // For example, if jug1 has 2 liters, jug2 has 3 liters, and the total amount of water is 5 liters,
    // we can represent these states as 0b110 (since 2+3+5=10, and 0b110 is 6 in binary)
    
    // Initialize the three variables
    let jug1 = 0;
    let jug2 = 0;
    let total = jug1 + jug2;
    
    // We use a loop to iterate until we find a state where the total amount of water equals to the target
    while (total!== target) {
        // Fill the first jug
        jug1 = Math.min(x, total);
        total -= jug1;
        
        // Fill the second jug
        jug2 = Math.min(y, total);
        total -= jug2;
        
        // Pour water from the first jug into the second jug until the second jug becomes full
        while (jug1 > 0 && jug2 < y) {
            jug2++;
            jug1--;
        }
        
        // Pour water from the second jug into the first jug until the first jug becomes full
        while (jug2 > 0 && jug1 < x) {
            jug1++;
            jug2--;
        }
    }
    
    // If we find a state where the total amount of water equals to the target, return true
    return true;
    
};