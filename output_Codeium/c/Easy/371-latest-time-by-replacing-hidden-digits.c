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
    int h1 = time[0] == '?' ? 2 : time[0] - '0';
    int h2 = time[1] == '?' ? 3 : time[1] - '0';
    int m1 = time[3] == '?' ? 5 : time[3] - '0';
    int m2 = time[4] == '?' ? 9 : time[4] - '0';
    
    time[0] = h1 < 2 ? '2' : '1';
    time[1] = h2 < 4 ? '3' : '0' + h2 - 1;
    time[3] = m1 < 6 ? '5' : '0' + m1 - 1;
    time[4] = '0' + m2;
    
    return time;
}