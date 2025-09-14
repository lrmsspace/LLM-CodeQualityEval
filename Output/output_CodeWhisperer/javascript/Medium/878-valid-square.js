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
    let distances = [];
    distances.push(distance(p1, p2));
    distances.push(distance(p1, p3));
    distances.push(distance(p1, p4));
    distances.push(distance(p2, p3));
    distances.push(distance(p2, p4));
    distances.push(distance(p3, p4));
    distances.sort((a, b) => a - b);
    return distances[0] > 0 && distances[0] === distances[1] && distances[1] === distances[2] && distances[2] === distances[3] && distances[3] === distances[4] && distances[4] === distances[5] && distances[5] < distances[6];

};