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
bool haveConflict(char** event1, int event1Size, char** event2, int event2Size) {
    int start1 = (event1[0][0] - '0') * 600 + (event1[0][1] - '0') * 60 + (event1[0][3] - '0') * 10 + event1[0][4] - '0';
    int end1 = (event1[1][0] - '0') * 600 + (event1[1][1] - '0') * 60 + (event1[1][3] - '0') * 10 + event1[1][4] - '0';
    int start2 = (event2[0][0] - '0') * 600 + (event2[0][1] - '0') * 60 + (event2[0][3] - '0') * 10 + event2[0][4] - '0';
    int end2 = (event2[1][0] - '0') * 600 + (event2[1][1] - '0') * 60 + (event2[1][3] - '0') * 10 + event2[1][4] - '0';
    if (start1 <= start2 && end1 >= start2) {
        return true;
    }
    if (start2 <= start1 && end2 >= start1) {
        return true;
    }
    return false;
    
}