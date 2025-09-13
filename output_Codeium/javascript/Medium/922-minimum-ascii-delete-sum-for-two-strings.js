/**https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ */
//Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
// 
//Example 1:
//Input: s1 = "sea", s2 = "eat"
//Output: 231
//Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//Deleting "t" from "eat" adds 116 to the sum.
//At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//Example 2:
//Input: s1 = "delete", s2 = "leet"
//Output: 403
//Explanation: Deleting "dee" from "delete" to turn the string into "let",
//adds 100[d] + 101[e] + 101[e] to the sum.
//Deleting "e" from "leet" adds 101[e] to the sum.
//At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
//If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 1000
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumDeleteSum = function(s1, s2) {
    let sum = 0;
    let i = 0, j = 0;
    while (i < s1.length && j < s2.length) {
        if (s1[i] === s2[j]) {
            i++;
            j++;
        } else {
            sum += s1[i] < s2[j] ? s1.charCodeAt(i++) : s2.charCodeAt(j++);
        }
    }
    while (i < s1.length) sum += s1.charCodeAt(i++);
    while (j < s2.length) sum += s2.charCodeAt(j++);
    return sum;
};