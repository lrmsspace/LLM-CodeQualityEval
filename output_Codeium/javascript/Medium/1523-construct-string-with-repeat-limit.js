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
    const charCounts = {};
    for (const char of s) {
        charCounts[char] = (charCounts[char] || 0) + 1;
    }
    const sortedChars = Object.keys(charCounts).sort((a, b) => charCounts[b] - charCounts[a]);
    const result = [];
    for (const char of sortedChars) {
        let count = charCounts[char];
        while (count > 0) {
            const limit = Math.min(count, repeatLimit);
            result.push(char.repeat(limit));
            count -= limit;
            if (count > 0) {
                for (let i = sortedChars.length - 1; i >= 0; i--) {
                    const otherChar = sortedChars[i];
                    if (otherChar !== char) {
                        result.push(otherChar);
                        count--;
                        break;
                    }
                }
            }
        }
    }
    return result.join('');
    
};