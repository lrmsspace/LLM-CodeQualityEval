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
    let time = [];
    for(let i = 0; i < timePoints.length; i++){
        let hour = parseInt(timePoints[i].slice(0,2));
        let min = parseInt(timePoints[i].slice(3));
        time.push(hour*60 + min);
    }
    time.sort((a,b)=>a-b);
    let min = 1440;
    for(let i = 0; i < time.length; i++){
        let diff = Math.abs(time[i] - time[i-1]);
        if(diff < min){
            min = diff;
        }
    }
    return min;

};