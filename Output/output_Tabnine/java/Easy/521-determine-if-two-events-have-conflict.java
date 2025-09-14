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
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        int start1 = Integer.parseInt(event1[0].replace(":", ""));
        int end1 = Integer.parseInt(event1[1].replace(":", ""));
        int start2 = Integer.parseInt(event2[0].replace(":", ""));
        int end2 = Integer.parseInt(event2[1].replace(":", ""));
        
        return Math.max(start1, start2) < Math.min(end1, end2); // if there is a non-empty intersection, the start time of the later event must be less than the end time of the earlier event.  Otherwise, they do not intersect.
        
    }
}