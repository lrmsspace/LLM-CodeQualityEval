/**https://leetcode.com/problems/self-crossing/ */
//You are given an array of integers distance.
//You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
//Return true if your path crosses itself or false if it does not.
// 
//Example 1:
//Input: distance = [2,1,1,2]
//Output: true
//Explanation: The path crosses itself at the point (0, 1).
//Example 2:
//Input: distance = [1,2,3,4]
//Output: false
//Explanation: The path does not cross itself at any point.
//Example 3:
//Input: distance = [1,1,1,2,1]
//Output: true
//Explanation: The path crosses itself at the point (0, 0).
// 
//Constraints:
//	1 <= distance.length <= 105
//	1 <= distance[i] <= 105
/**
 * @param {number[]} distance
 * @return {boolean}
 */
var isSelfCrossing = function(distance) {
    let x = 0, y = 0;
    let directions = [[0, 1], [-1, 0], [0, -1], [1, 0]];
    let visited = [[0, 0]];
    let directionIndex = 0;
    for (let i = 0; i < distance.length; i++) {
        for (let j = 0; j < distance[i]; j++) {
            x += directions[directionIndex][0];
            y += directions[directionIndex][1];
            for (let k = 0; k < visited.length; k++) {
                if (visited[k][0] === x && visited[k][1] === y) {
                    return true;
                }
            }
            visited.push([x, y]);
        }
        directionIndex = (directionIndex + 1) % 4;
    }
    return false;
};