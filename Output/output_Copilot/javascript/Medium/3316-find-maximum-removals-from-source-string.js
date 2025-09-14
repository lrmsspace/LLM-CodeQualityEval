/*
 You are given a string source of size n, a string pattern that is a subsequence of source, and a sorted integer array targetIndices that contains distinct numbers in the range [0, n - 1].
 We define an operation as removing a character at an index idx from source such that:
 idx is an element of targetIndices.
 pattern remains a subsequence of source after removing the character.
 Performing an operation does not change the indices of the other characters in source. For example, if you remove 'c' from "acb", the character at index 2 would still be 'b'.
 Return the maximum number of operations that can be performed.
 Example 1:
 Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
 Output: 1
 Explanation:
 We can't remove source[0] but we can do either of these two operations:
 Remove source[1], so that source becomes "a_baa".
 Remove source[2], so that source becomes "ab_aa".
 Example 2:
 Input: source = "bcda", pattern = "d", targetIndices = [0,3]
 Output: 2
 Explanation:
 We can remove source[0] and source[3] in two operations.
 Example 3:
 Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]
 Output: 0
 Explanation:
 We can't remove any character from source.
 Example 4:
 Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
 Output: 2
 Explanation:
 We can remove source[2] and source[3] in two operations.
 Constraints:
 1 <= n == source.length <= 3 * 103
 1 <= pattern.length <= n
 1 <= targetIndices.length <= n
 targetIndices is sorted in ascending order.
 The input is generated such that targetIndices contains distinct elements in the range [0, n - 1].
 source and pattern consist only of lowercase English letters.
 The input is generated such that pattern appears as a subsequence in source.
*/

/**
 * @param {string} source
 * @param {string} pattern
 * @param {number[]} targetIndices
 * @return {number}
 */
var maxRemovals = function(source, pattern, targetIndices) {
    const n = source.length;
    const m = pattern.length;
    const targetSet = new Set(targetIndices);
    let maxRemovals = 0;

    // Function to check if pattern is a subsequence of source after removing characters at target indices
    const isSubsequence = (source, pattern, removedIndices) => {
        let j = 0; // Pointer for pattern
        for (let i = 0; i < source.length; i++) {
            if (removedIndices.has(i)) continue; // Skip removed indices
            if (source[i] === pattern[j]) {
                j++;
                if (j === pattern.length) return true; // Found the whole pattern
            }
        }
        return j === pattern.length; // Check if we matched the whole pattern
    };

    // Try removing each character in targetIndices and check if pattern remains a subsequence
    for (let idx of targetIndices) {
        if (isSubsequence(source, pattern, new Set([idx]))) {
            maxRemovals++;
        } else {
            break; // If we can't remove this index, we can't remove any further ones
        }
    }

    return maxRemovals;
        
};