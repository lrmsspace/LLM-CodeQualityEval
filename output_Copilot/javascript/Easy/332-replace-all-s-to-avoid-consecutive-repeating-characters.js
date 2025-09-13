/**https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/ */
//Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.
//It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
//Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.
// 
//Example 1:
//Input: s = "?zs"
//Output: "azs"
//Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
//Example 2:
//Input: s = "ubv?w"
//Output: "ubvaw"
//Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
// 
//Constraints:
//	1 <= s.length <= 100
//	s consist of lowercase English letters and '?'.
/**
 * @param {string} s
 * @return {string}
 */
var modifyString = function(s) {
    let result = s.split('');
    for (let i = 0; i < result.length; i++) {
        if (result[i] === '?') {
            for (let j = 0; j < 26; j++) {
                let char = String.fromCharCode(97 + j);
                if ((i === 0 || result[i - 1] !== char) && (i === result.length - 1 || result[i + 1] !== char)) {
                    result[i] = char;
                    break;
                }
            }
        }
    }
    return result.join('');    
};