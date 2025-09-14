/**https://leetcode.com/problems/determine-if-two-events-have-conflict/ */
//You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:
//	event1 = [startTime1, endTime1] and
//	event2 = [startTime2, endTime2].
//Event times are valid 24 hours format in the form of HH:MM.
//A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).
//Return true if there is a conflict between two events. Otherwise, return false.
// 
//Example 1:
//Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
//Output: true
//Explanation: The two events intersect at time 2:00.
//Example 2:
//Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
//Output: true
//Explanation: The two events intersect starting from 01:20 to 02:00.
//Example 3:
//Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
//Output: false
//Explanation: The two events do not intersect.
// 
//Constraints:
//	event1.length == event2.length == 2
//	event1[i].length == event2[i].length == 5
//	startTime1 <= endTime1
//	startTime2 <= endTime2
//	All the event times follow the HH:MM format.
/**
 * @param {string[]} event1
 * @param {string[]} event2
 * @return {boolean}
 */
var haveConflict = function(event1, event2) {
    let [start1, end1] = event1.map(time => time.split(':'));
    let [start2, end2] = event2.map(time => time.split(':'));
    
    let s1 = parseInt(start1[0]) * 60 + parseInt(start1[1]);
    let e1 = parseInt(end1[0]) * 60 + parseInt(end1[1]);
    
    let s2 = parseInt(start2[0]) * 60 + parseInt(start2[1]);
    let e2 = parseInt(end2[0]) * 60 + parseInt(end2[1]);
    
    return Math.max(s1, s2) < Math.min(e1, e2);
    
};