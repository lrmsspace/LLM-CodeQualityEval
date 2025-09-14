/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let max = Math.max(a, b, c);
    let maxChar = '';
    if (max === a) maxChar = 'a';
    else if (max === b) maxChar = 'b';
    else maxChar = 'c';
    let maxCount = max;
    let secondMax = Math.min(a, b, c);
    let secondMaxChar = '';
    if (secondMax === a) secondMaxChar = 'a';
    else if (secondMax === b) secondMaxChar = 'b';
    else secondMaxChar = 'c';
    let secondMaxCount = secondMax;
    let thirdMax = Math.max(a, b, c);
    let thirdMaxChar = '';
    if (thirdMax === a) thirdMaxChar = 'a';
    else if (thirdMax === b) thirdMaxChar = 'b';
    else thirdMaxChar = 'c';
    let thirdMaxCount = thirdMax;
    let result = '';
    while (maxCount > 0 || secondMaxCount > 0 || thirdMaxCount > 0) {
        if (maxCount > 0) {
            result += maxChar;
            maxCount--;
            if (secondMaxCount > 0) {
                if (secondMaxCount > 1) {
                    result += secondMaxChar;
                    secondMaxCount--;
                } else {
                    result += secondMaxChar + secondMaxChar;
                    secondMaxCount -= 2;
                }
            } else {
                if (thirdMaxCount > 1) {
                    result += thirdMaxChar;
                    thirdMaxCount--;
               } else {
                  result += thirdMaxChar + thirdMaxChar;
               }
            }
        }
    }
    return result;
};