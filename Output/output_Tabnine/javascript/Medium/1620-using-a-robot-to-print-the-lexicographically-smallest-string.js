/**https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/ */
//You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//	Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//	Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//Return the lexicographically smallest string that can be written on the paper.
// 
//Example 1:
//Input: s = "zza"
//Output: "azz"
//Explanation: Let p denote the written string.
//Initially p="", s="zza", t="".
//Perform first operation three times p="", s="", t="zza".
//Perform second operation three times p="azz", s="", t="".
//Example 2:
//Input: s = "bac"
//Output: "abc"
//Explanation: Let p denote the written string.
//Perform first operation twice p="", s="c", t="ba". 
//Perform second operation twice p="ab", s="c", t="". 
//Perform first operation p="ab", s="", t="c". 
//Perform second operation p="abc", s="", t="".
//Example 3:
//Input: s = "bdda"
//Output: "addb"
//Explanation: Let p denote the written string.
//Initially p="", s="bdda", t="".
//Perform first operation four times p="", s="", t="bdda".
//Perform second operation four times p="addb", s="", t="".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
/**
 * @param {string} s
 * @return {string}
 */
var robotWithString = function(s) {
    // If the string is empty, return an empty string
    if (s.length === 0) {
        return '';
    }
    
    // Initialize an empty string for the robot's work
    let robot = '';
    
    // Iterate over the string from left to right
    for (let i = 0; i < s.length; i++) {
        // Append the current character to the robot's work
        robot += s[i];
        
        // If the robot's work is lexicographically smaller than the remaining string,
        // we need to remove the last character of the robot's work
        if (robot < s.slice(i + 1)) {
            robot = robot.slice(0, -1);
        }
    }
    
    return robot;
    
};