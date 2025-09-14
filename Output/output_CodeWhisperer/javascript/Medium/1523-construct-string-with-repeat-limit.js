/**https://leetcode.com/problems/construct-string-with-repeat-limit/ */
//You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
//Return the lexicographically largest repeatLimitedString possible.
//A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
// 
//Example 1:
//Input: s = "cczazcc", repeatLimit = 3
//Output: "zzcccac"
//Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
//The letter 'a' appears at most 1 time in a row.
//The letter 'c' appears at most 3 times in a row.
//The letter 'z' appears at most 2 times in a row.
//Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
//The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
//Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
//Example 2:
//Input: s = "aababab", repeatLimit = 2
//Output: "bbabaa"
//Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
//The letter 'a' appears at most 2 times in a row.
//The letter 'b' appears at most 2 times in a row.
//Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
//The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
//Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
// 
//Constraints:
//	1 <= repeatLimit <= s.length <= 105
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @param {number} repeatLimit
 * @return {string}
 */
var repeatLimitedString = function(s, repeatLimit) {
    let count = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    let result = '';
    let last = 25;
    let repeat = 0;
    while (last >= 0) {
        if (count[last] === 0) {
            last--;
            repeat = 0;
        } else if (repeat < repeatLimit) {
            result += String.fromCharCode(last + 'a'.charCodeAt(0));
            count[last]--;
            repeat++;
        } else {
            let next = last - 1;
            while (next >= 0 && count[next] === 0) {
                next--;
            }
            if (next < 0) {
                break;
            }
            result += String.fromCharCode(next + 'a'.charCodeAt(0));
            count[next]--;
            repeat = 1;
        }
    }
    return result;
};