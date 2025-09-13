/*
 Given a string s, you need to partition it into one or more balanced substrings. For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.
 Return the minimum number of substrings that you can partition s into.
 Note: A balanced string is a string where each character in the string occurs the same number of times.
 Example 1:
 Input: s = "fabccddg"
 Output: 3
 Explanation:
 We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
 Example 2:
 Input: s = "abababaccddb"
 Output: 2
 Explanation:
 We can partition the string s into 2 substrings like so: ("abab", "abaccddb").
 Constraints:
 1 <= s.length <= 1000
 s consists only of English lowercase letters.
*/

/**
 * @param {string} s
 * @return {number}
 */
var minimumSubstringsInPartition = function(s) {
    const n = s.length;
    const freq = Array(26).fill(0);
    let uniqueChars = 0;
    let partitions = 0;

    for (let i = 0; i < n; i++) {
        const charIndex = s.charCodeAt(i) - 'a'.charCodeAt(0);
        if (freq[charIndex] === 0) {
            uniqueChars++;
        }
        freq[charIndex]++;
        
        // Check if we can form a balanced substring
        if (uniqueChars > 1) {
            let minFreq = Infinity;
            let maxFreq = -Infinity;
            for (let j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    minFreq = Math.min(minFreq, freq[j]);
                    maxFreq = Math.max(maxFreq, freq[j]);
                }
            }
            if (minFreq === maxFreq) {
                partitions++;
                freq.fill(0);
                uniqueChars = 0;
            }
        }
    }

    // If there are remaining characters, they form one more partition
    if (uniqueChars > 0) {
        partitions++;
    }

    return partitions;    
};