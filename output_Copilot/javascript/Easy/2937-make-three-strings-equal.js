/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/

/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {number}
 */
var findMinimumOperations = function(s1, s2, s3) {
    // Find the length of the longest common suffix
    let len1 = s1.length, len2 = s2.length, len3 = s3.length;
    let i = 0;

    while (i < len1 && i < len2 && i < len3 && s1[len1 - 1 - i] === s2[len2 - 1 - i] && s1[len1 - 1 - i] === s3[len3 - 1 - i]) {
        i++;
    }

    // If no common suffix, return -1
    if (i === 0) {
        return -1;
    }

    // Calculate the number of operations needed
    return (len1 - i) + (len2 - i) + (len3 - i);
    
};