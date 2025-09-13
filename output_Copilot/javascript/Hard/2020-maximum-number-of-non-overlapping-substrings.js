/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//	A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.
// 
//Example 1:
//Input: s = "adefaddaccc"
//Output: ["e","f","ccc"]
//Explanation: The following are all the possible substrings that meet the conditions:
//[
//  "adefaddaccc"
//  "adefadda",
//  "ef",
//  "e",
//  "f",
//  "ccc",
//]
//If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
//Example 2:
//Input: s = "abbaccd"
//Output: ["d","bb","cc"]
//Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string[]}
 */
var maxNumOfSubstrings = function(s) {
    const n = s.length;
    const last = new Array(26).fill(-1);
    const first = new Array(26).fill(-1);
    const result = [];
    let maxLength = 0;

    for (let i = 0; i < n; i++) {
        const charCode = s.charCodeAt(i) - 'a'.charCodeAt(0);
        if (first[charCode] === -1) {
            first[charCode] = i;
        }
        last[charCode] = i;
    }

    for (let i = 0; i < n; i++) {
        const charCode = s.charCodeAt(i) - 'a'.charCodeAt(0);
        let start = first[charCode];
        let end = last[charCode];
        for (let j = start; j <= end; j++) {
            const nextCharCode = s.charCodeAt(j) - 'a'.charCodeAt(0);
            end = Math.max(end, last[nextCharCode]);
        }
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            result.length = 0;
            result.push(s.substring(start, end + 1));
        } else if (end - start + 1 === maxLength) {
            result.push(s.substring(start, end + 1));
        }
    }

    return result;    
};