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
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1 = event1[0], s2 = event1[1];
        string s3 = event2[0], s4 = event2[1];
        int t1 = stoi(s1.substr(0, 2)) * 60 + stoi(s1.substr(3, 2));
        int t2 = stoi(s2.substr(0, 2)) * 60 + stoi(s2.substr(3, 2));
        int t3 = stoi(s3.substr(0, 2)) * 60 + stoi(s3.substr(3, 2));
        int t4 = stoi(s4.substr(0, 2)) * 60 + stoi(s4.substr(3, 2));
        return max(t1, t3) <= min(t2, t4);
    }
};