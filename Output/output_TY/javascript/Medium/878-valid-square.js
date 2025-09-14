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
    
    let dist = (a, b) => Math.sqrt(Math.pow(Math.abs(a[0] - b[0]), 2) + Math.pow(Math.abs(a[1] - b[1]), 2));
    
    let d1 = dist(p1, p2);
    let d2 = dist(p1, p3);
    let d3 = dist(p1, p4);
    let d4 = dist(p2, p3);
    let d5 = dist(p2, p4);
    let d6 = dist(p3, p4);
    
    let set = new Set([d1, d2, d3, d4, d5, d6]);
    
    if (set.size !== 2) return false;
    
    let max = Math.max(...set);
    let min = Math.min(...set);
    
    return max !== 0 && max === 2 * min;
};