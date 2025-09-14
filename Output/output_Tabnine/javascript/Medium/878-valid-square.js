/**https://leetcode.com/problems/valid-square/ */
//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//	p1.length == p2.length == p3.length == p4.length == 2
//	-104 <= xi, yi <= 104
/**
 * @param {number[]} p1
 * @param {number[]} p2
 * @param {number[]} p3
 * @param {number[]} p4
 * @return {boolean}
 */
var validSquare = function(p1, p2, p3, p4) {
    // Calculate the distance between two points
    function distance(p1, p2) {
        return Math.sqrt(Math.pow(p2[0] - p1[0], 2) + Math.pow(p2[1] - p1[1], 2));
    }
    
    // Calculate the lengths of all sides
    const side1 = distance(p1, p2);
    const side2 = distance(p2, p3);
    const side3 = distance(p3, p4);
    const side4 = distance(p4, p1);
    
    // Check if the sides are equal
    if (side1!== side2 || side2!== side3 || side3!== side4) {
        return false;
    }
    
    // Check if the angles are 90 degrees
    const angle1 = Math.acos((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3));
    const angle2 = Math.acos((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3));
    const angle3 = Math.acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
    const angle4 = Math.acos((side2 * side2 + side4 * side4 - side1 * side1) / (2 * side2 * side4));
    
    return Math.abs(Math.round(angle1 * 180 / Math.PI) - 90) <= 1 &&
        Math.abs(Math.round(angle2 * 180 / Math.PI) - 90) <= 1 &&
        Math.abs(Math.round(angle3 * 180 / Math.PI) - 90) <= 1 &&
        Math.abs(Math.round(angle4 * 180 / Math.PI) - 90) <= 1;
    
};