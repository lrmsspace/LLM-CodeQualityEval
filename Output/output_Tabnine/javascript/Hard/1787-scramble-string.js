/**https://leetcode.com/problems/scramble-string/ */
//We can scramble a string s to get a string t using the following algorithm:
//	If the length of the string is 1, stop.
//	If the length of the string is > 1, do the following:
//	
//		Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
//		Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
//		Apply step 1 recursively on each of the two substrings x and y.
//	
//	
//Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
// 
//Example 1:
//Input: s1 = "great", s2 = "rgeat"
//Output: true
//Explanation: One possible scenario applied on s1 is:
//"great" --> "gr/eat" // divide at random index.
//"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
//"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
//"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
//"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
//"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
//The algorithm stops now, and the result string is "rgeat" which is s2.
//As one possible scenario led s1 to be scrambled to s2, we return true.
//Example 2:
//Input: s1 = "abcde", s2 = "caebd"
//Output: false
//Example 3:
//Input: s1 = "a", s2 = "a"
//Output: true
// 
//Constraints:
//	s1.length == s2.length
//	1 <= s1.length <= 30
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    // If the strings are empty or have different lengths, they cannot be scrambled
    if (s1.length === 0 || s2.length === 0 || s1.length!== s2.length) {
        return false;
    }
    
    // If the strings are identical, they are scrambled
    if (s1 === s2) {
        return true;
    }
    
    // Count the frequency of each character in s1
    let charCount = Array(26).fill(0);
    for (let i = 0; i < s1.length; i++) {
        charCount[s1.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    
    // Check if the frequency of each character in s1 is the same as in s2
    for (let i = 0; i < 26; i++) {
        if (charCount[i]!== s2.split('').reduce((acc, char) => acc + (char.charCodeAt(0) - 'a'.charCodeAt(0)), 0)) {
            return false;
        }
    }
    
    // Try all possible splits of s1 into two non-empty substrings
    for (let i = 1; i < s1.length; i++) {
        // Check if the current split is a valid scramble
        if (isScramble(s1.slice(0, i), s2.slice(0, i)) && isScramble(s1.slice(i), s2.slice(i))) {
            return true;
        }
        
        // Check if the swapped split is a valid scramble
        if (isScramble(s1.slice(0, i), s2.slice(s2.length - i)) && isScramble(s1.slice(i), s2.slice(0, s2.length - i))) {
            return true;
        }
    }
    
    // If no valid split is found, the strings cannot be scrambled
    return false;
    
};