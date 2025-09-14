/**https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/ */
//You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).
//The valid times are those inclusively between 00:00 and 23:59.
//Return the latest valid time you can get from time by replacing the hidden digits.
// 
//Example 1:
//Input: time = "2?:?0"
//Output: "23:50"
//Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
//Example 2:
//Input: time = "0?:3?"
//Output: "09:39"
//Example 3:
//Input: time = "1?:22"
//Output: "19:22"
// 
//Constraints:
//	time is in the format hh:mm.
//	It is guaranteed that you can produce a valid time from the given string.
class Solution {
public:
    string maximumTime(string time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        
        if (time[0] == '?' && time[1] == '?') {
            h = max(h, 9);
        } else if (time[0] == '?') {
            h = max(h, stoi(time[1] == '2'? "2" : "1"));
        }
        
        if (time[3] == '?' && time[4] == '?') {
            m = max(m, 9);
        } else if (time[3] == '?') {
            m = max(m, stoi(time[4] == '5'? "5" : "4"));
        }
        
        return to_string(h).size() == 1? "0" + to_string(h) : to_string(h) + ":" + (to_string(m).size() == 1? "0" + to_string(m) : to_string(m));
        
    }
};