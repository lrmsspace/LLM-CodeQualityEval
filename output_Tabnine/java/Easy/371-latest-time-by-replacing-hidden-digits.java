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
    public String maximumTime(String time) {
        
        int h = Character.getNumericValue(time.charAt(0)) * 10 + Character.getNumericValue(time.charAt(1));
        int m = Character.getNumericValue(time.charAt(3)) * 10 + Character.getNumericValue(time.charAt(4));
        
        if (time.charAt(0) == '?' || h < 24) {
            time = time.substring(0, 1) + (h < 10? "0" + h : Integer.toString(h)) + time.substring(2);
        }
        
        if (time.charAt(3) == '?' || m < 60) {
            time = time.substring(0, 3) + (m < 10? "0" + m : Integer.toString(m)) + time.substring(5);
        }
        
        return time;
    }
}