/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    timePoints.sort((a, b) => a.localeCompare(b));
    let min = Infinity;
    for (let i = 1; i < timePoints.length; i++) {
        const [h1, m1] = timePoints[i-1].split(':').map(Number);
        const [h2, m2] = timePoints[i].split(':').map(Number);
        const diff = (h2 - h1) * 60 + (m2 - m1);
        min = Math.min(min, diff);
    }
    const [h1, m1] = timePoints[timePoints.length-1].split(':').map(Number);
    const [h2, m2] = timePoints[0].split(':').map(Number);
    const diff = (h2 + 24 - h1) * 60 + (m2 - m1);
    return Math.min(min, diff);
};