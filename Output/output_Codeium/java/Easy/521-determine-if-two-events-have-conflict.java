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
        String[] t1 = event1[0].split(":");
        String[] t2 = event1[1].split(":");
        String[] t3 = event2[0].split(":");
        String[] t4 = event2[1].split(":");
        
        int s1 = Integer.parseInt(t1[0]) * 60 + Integer.parseInt(t1[1]);
        int e1 = Integer.parseInt(t2[0]) * 60 + Integer.parseInt(t2[1]);
        int s2 = Integer.parseInt(t3[0]) * 60 + Integer.parseInt(t3[1]);
        int e2 = Integer.parseInt(t4[0]) * 60 + Integer.parseInt(t4[1]);
        
        return !(s1 >= e2 || s2 >= e1);
    }
}