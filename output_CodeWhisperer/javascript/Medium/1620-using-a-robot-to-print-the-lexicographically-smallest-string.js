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
    // Initialize variables
    const n = s.length;
    const stack = [];
    let result = '';
    
    // Create suffix min array to store minimum character after each position
    const suffixMin = new Array(n + 1).fill('z');
    suffixMin[n] = 'z';
    
    // Fill suffix min array from right to left
    for (let i = n - 1; i >= 0; i--) {
        suffixMin[i] = String.fromCharCode(Math.min(
            s[i].charCodeAt(0),
            suffixMin[i + 1].charCodeAt(0)
        ));
    }
    
    // Process each character
    let i = 0;
    while (i < n) {
        // If stack is empty or current char is smaller than suffix min,
        // push current char to stack
        if (stack.length === 0 || 
            stack[stack.length - 1] > suffixMin[i]) {
            stack.push(s[i]);
            i++;
        } else {
            // Pop from stack if top of stack is smaller or equal
            result += stack.pop();
        }
    }
    
    // Empty the remaining stack
    while (stack.length > 0) {
        result += stack.pop();
    }
    
    return result;
};
