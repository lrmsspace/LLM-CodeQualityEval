/*
 You are given a string s, which is known to be a concatenation of anagrams of some string t.
 Return the minimum possible length of the string t.
 An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
 Example 1:
 Input: s = "abba"
 Output: 2
 Explanation:
 One possible string t could be "ba".
 Example 2:
 Input: s = "cdef"
 Output: 4
 Explanation:
 One possible string t could be "cdef", notice that t can be equal to s.
 Example 2:
 Input: s = "abcbcacabbaccba"
 Output: 3
 Constraints:
 1 <= s.length <= 105
 s consist only of lowercase English letters.
*/

/**
 * @param {string} s
 * @return {number}
 */
var minAnagramLength = function(s) {
    const freq = new Map();
    let minLen = Infinity;
    
    // Count the frequency of each character in s
    for (let char of s) {
        freq.set(char, (freq.get(char) || 0) + 1);
    }
    
    // Initialize a window with a size of 1
    let left = 0;
    let right = 0;
    let count = 0;
    while (right < s.length) {
        // Add the character at the right pointer to the window
        freq.set(s[right], (freq.get(s[right]) || 0) - 1);
        if (freq.get(s[right]) === 0) {
            count++;
        }
        
        // Slide the window until it contains all anagrams of t
        while (count === freq.size) {
            minLen = Math.min(minLen, right - left + 1);
            
            // Remove the character at the left pointer from the window
            freq.set(s[left], (freq.get(s[left]) || 0) + 1);
            if (freq.get(s[left]) === 1) {
                count--;
            }
            
            left++;
        }
        
        right++;
    
        // Reset the window to start from the next character
        freq.clear();
        for (let i = right; i < s.length; i++) {
            freq.set(s[i], (freq.get(s[i]) || 0) + 1);
        }
    }   
    return minLen;
    
};