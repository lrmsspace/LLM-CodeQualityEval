/**https://leetcode.com/problems/string-compression-ii/ */
//Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
//Notice that in this problem, we are not adding '1' after single characters.
//Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
//Find the minimum length of the run-length encoded version of s after deleting at most k characters.
// 
//Example 1:
//Input: s = "aaabcccd", k = 2
//Output: 4
//Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
//Example 2:
//Input: s = "aabbaa", k = 2
//Output: 2
//Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
//Example 3:
//Input: s = "aaaaaaaaaaa", k = 0
//Output: 3
//Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
// 
//Constraints:
//	1 <= s.length <= 100
//	0 <= k <= s.length
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLengthOfOptimalCompression = function(s, k) {
    // Initialize variables
    let maxLength = s.length;
    let count = 1;
    
    // Iterate through the string
    for (let i = 1; i < s.length; i++) {
        // If current character is the same as previous one
        if (s[i] === s[i - 1]) {
            count++;
        } else {
            // If current character is different from previous one and k is greater than 0
            if (k > 0) {
                // Decrement k and add current character to the compressed string
                k--;
                maxLength--;
            }
            // Add count of previous character to the compressed string
            maxLength -= count.toString().length;
            maxLength += count + 1;
            count = 1;
        }
    }
    
    // Add count of last character to the compressed string
    maxLength -= count.toString().length;
    maxLength += count + 1;
    
    return maxLength;
    
};