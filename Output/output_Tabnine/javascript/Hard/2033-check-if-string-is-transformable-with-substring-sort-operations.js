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
    // Step 1: Sort the characters in both strings
    let sArr = [...s].sort((a, b) => a - b);
    let tArr = [...t].sort((a, b) => a - b);
    
    // Step 2: Iterate over the characters in both strings
    let i = 0;
    let j = 0;
    while (i < sArr.length && j < tArr.length) {
        // Step 3: If the characters are different, check if they can be transformed
        if (sArr[i]!== tArr[j]) {
            // Step 3.1: Check if the current character in s can be transformed into the current character in t
            if (!isTransformable(sArr[i], tArr[j])) {
                return false;
            }
            
            // Step 3.2: Remove the transformed character from s
            let index = s.indexOf(sArr[i]);
            s = s.slice(0, index) + s.slice(index + 1);
            
            // Step 3.3: Update the pointers
            i--;
        } else {
            // Step 4: Move the pointers
            i++;
            j++;
        }
    }
    
    // Step 5: Check if there are any remaining characters in s
    return s === '';
    
};