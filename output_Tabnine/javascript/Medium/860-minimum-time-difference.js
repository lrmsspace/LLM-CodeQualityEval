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
    // Sort the time points in ascending order
    timePoints.sort((a, b) => {
        const [hourA, minuteA] = a.split(':').map(Number);
        const [hourB, minuteB] = b.split(':').map(Number);
        
        return hourA * 60 + minuteA - (hourB * 60 + minuteB);
    });
    
    let minDiff = Infinity;
    
    // Iterate over the sorted time points
    for (let i = 1; i < timePoints.length; i++) {
        const [hourA, minuteA] = timePoints[i - 1].split(':').map(Number);
        const [hourB, minuteB] = timePoints[i].split(':').map(Number);
        
        // Calculate the difference in hours and minutes
        const diffHours = Math.abs(hourA - hourB);
        const diffMinutes = Math.abs(minuteA - minuteB);
        
        // Update the minimum difference if necessary
        minDiff = Math.min(minDiff, diffHours * 60 + diffMinutes);
    }
    
    // Handle the case when the time points span across midnight
    const [lastHour, lastMinute] = timePoints[timePoints.length - 1].split(':').map(Number);
    const [firstHour, firstMinute] = timePoints[0].split(':').map(Number);
    
    const midnightDiffHours = Math.abs(lastHour - firstHour);
    const midnightDiffMinutes = Math.abs(lastMinute - firstMinute);
    
    minDiff = Math.min(minDiff, midnightDiffHours * 60 + midnightDiffMinutes);
    
    return minDiff;
    
};