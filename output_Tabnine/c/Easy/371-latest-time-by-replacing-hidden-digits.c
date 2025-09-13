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
char* maximumTime(char* time) {
    int hours = (time[0] - '0') * 10 + time[1] - '0';
    int minutes = (time[3] - '0') * 10 + time[4] - '0';
    
    if (time[0] == '?') {
        if (hours < 24) time[0] = hours / 10 + '0';
        else time[0] = '2';
    }
    
    if (time[1] == '?') {
        if (hours % 10 == 9) time[1] = '9';
        else time[1] = hours % 10 + '0';
    }
    
    if (time[3] == '?') {
        if (minutes < 60) time[3] = minutes / 10 + '0';
        else time[3] = '5';
    }
    
    if (time[4] == '?') {
        if (minutes % 10 == 9) time[4] = '9';
        else time[4] = minutes % 10 + '0';
    }
    
    return time;
    
}