/*
 You are given a string s and a pattern string p, where p contains exactly two '*' characters.
 The '*' in p matches any sequence of zero or more characters.
 Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
 Note: The empty substring is considered valid.
 Example 1:
 Input: s = "abaacbaecebce", p = "ba*c*ce"
 Output: 8
 Explanation:
 The shortest matching substring of p in s is "baecebce".
 Example 2:
 Input: s = "baccbaadbc", p = "cc*baa*adb"
 Output: -1
 Explanation:
 There is no matching substring in s.
 Example 3:
 Input: s = "a", p = "**"
 Output: 0
 Explanation:
 The empty substring is the shortest matching substring.
 Example 4:
 Input: s = "madlogic", p = "*adlogi*"
 Output: 6
 Explanation:
 The shortest matching substring of p in s is "adlogi".
 Constraints:
 1 <= s.length <= 105
 2 <= p.length <= 105
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly two '*'.
*/

/**
 * @param {string} s
 * @param {string} p
 * @return {number}
 */
var shortestMatchingSubstring = function(s, p) {
    const [firstStar, secondStar] = [p.indexOf('*'), p.lastIndexOf('*')];
    const prefix = p.slice(0, firstStar);
    const suffix = p.slice(secondStar + 1);

    let minLength = Infinity;

    for (let i = 0; i < s.length; i++) {
        for (let j = i + 1; j <= s.length; j++) {
            const substring = s.slice(i, j);
            if (substring.startsWith(prefix) && substring.endsWith(suffix)) {
                minLength = Math.min(minLength, substring.length);
            }
        }
    }

    return minLength === Infinity ? -1 : minLength;
};