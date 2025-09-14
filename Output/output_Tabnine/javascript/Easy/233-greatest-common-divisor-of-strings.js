/**https://leetcode.com/problems/greatest-common-divisor-of-strings/ */
//For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// 
//Example 1:
//Input: str1 = "ABCABC", str2 = "ABC"
//Output: "ABC"
//Example 2:
//Input: str1 = "ABABAB", str2 = "ABAB"
//Output: "AB"
//Example 3:
//Input: str1 = "LEET", str2 = "CODE"
//Output: ""
// 
//Constraints:
//	1 <= str1.length, str2.length <= 1000
//	str1 and str2 consist of English uppercase letters.
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    // Find the gcd of str1 and str2
    let gcd = (a, b) => {
        if (b === 0) return a;
        return gcd(b, a % b);
    };
    
    // Check if str2 is a substring of str1
    let isSubstring = (str1, str2) => {
        return str1.includes(str2);
    };
    
    // Find the length of the gcd
    let len = gcd(str1.length, str2.length);
    
    // Check if the gcd is a substring of both str1 and str2
    while (len > 0 && isSubstring(str1, str2.substr(0, len)) && isSubstring(str2, str1.substr(0, len))) {
        len--;
    }
    
    return str1.substr(0, len);
    
};