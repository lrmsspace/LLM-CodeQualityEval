/**https://leetcode.com/problems/repeated-dna-sequences/ */
//The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
//	For example, "ACGAATTCCG" is a DNA sequence.
//When studying DNA, it is useful to identify repeated sequences within the DNA.
//Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
// 
//Example 1:
//Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//Output: ["AAAAACCCCC","CCCCCAAAAA"]
//Example 2:
//Input: s = "AAAAAAAAAAAAA"
//Output: ["AAAAAAAAAA"]
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either 'A', 'C', 'G', or 'T'.
/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    const L = 10;
    const seen = new Set();
    const res = new Set();
    for (let i = 0; i < s.length - L + 1; i++) {
        const tmp = s.substring(i, i+L);
        if (seen.has(tmp)) {
            res.add(tmp);
        }
        seen.add(tmp);
    }
    return Array.from(res);
};