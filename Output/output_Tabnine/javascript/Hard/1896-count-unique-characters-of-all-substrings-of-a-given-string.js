/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters in s.
//	For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
// 
//Example 1:
//Input: s = "ABC"
//Output: 10
//Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
//Every substring is composed with only unique letters.
//Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
//Example 2:
//Input: s = "ABA"
//Output: 8
//Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
//Example 3:
//Input: s = "LEETCODE"
//Output: 92
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of uppercase English letters only.
/**
 * @param {string} s
 * @return {number}
 */
var uniqueLetterString = function(s) {
    let n = s.length;
    let count = new Array(n).fill(0);
    let prefix = new Array(n).fill(0);
    let suffix = new Array(n).fill(0);
    let res = 0;
    
    for (let i = 0; i < n; i++) {
        count[i] = i > 0? count[i - 1] : 0;
        if (s[i] in prefix) {
            prefix[i] = prefix[prefix[i] - 1] + count[i];
        } else {
            prefix[i] = count[i] + 1;
        }
    }
    
    for (let i = n - 1; i >= 0; i--) {
        count[i] = i < n - 1? count[i + 1] : 0;
        if (s[i] in suffix) {
            suffix[i] = suffix[suffix[i] + 1] + count[i];
        } else {
            suffix[i] = count[i] + 1;
        }
    }
    
    for (let i = 0; i < n; i++) {
        res += prefix[i] * suffix[i];
    }
    
    return res % (10 ** 9 + 7);
    
};