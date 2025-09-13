/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//	Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//	
//		For example, applying the operation on the underlined substring in "14234" results in "12344".
//	
//	
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "84532", t = "34852"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"84532" (from index 2 to 3) -> "84352"
//"84352" (from index 0 to 2) -> "34852"
//Example 2:
//Input: s = "34521", t = "23415"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"34521" -> "23451"
//"23451" -> "23415"
//Example 3:
//Input: s = "12345", t = "12435"
//Output: false
// 
//Constraints:
//	s.length == t.length
//	1 <= s.length <= 105
//	s and t consist of only digits.
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isTransformable = function(s, t) {
    let pos = new Array(10).fill(0).map(() => new Array());
    for (let i = 0; i < s.length; i++) {
        pos[parseInt(s[i])].push(i);
    }
    for (let i = 0; i < t.length; i++) {
        let d = parseInt(t[i]);
        if (pos[d].length === 0) return false;
        for (let j = 0; j < d; j++) {
            if (pos[j].length > 0 && pos[j][0] < pos[d][0]) return false;
        }
        pos[d].shift();
    }
    return true;
};