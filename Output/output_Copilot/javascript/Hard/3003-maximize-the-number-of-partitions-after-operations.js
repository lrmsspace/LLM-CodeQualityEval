/*
 You are given a string s and an integer k.
 First, you are allowed to change at most one index in s to another lowercase English letter.
 After that, do the following partitioning operation until s is empty:
 Choose the longest prefix of s containing at most k distinct characters.
 Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
 Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.
 Example 1:
 Input: s = "accca", k = 2
 Output: 3
 Explanation:
 The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".
 Then we perform the operations:
 The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
 Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
 Finally, we remove "a" and s becomes empty, so the procedure ends.
 Doing the operations, the string is divided into 3 partitions, so the answer is 3.
 Example 2:
 Input: s = "aabaab", k = 3
 Output: 1
 Explanation:
 Initially s contains 2 distinct characters, so whichever character we change, it will contain at most 3 distinct characters, so the longest prefix with at most 3 distinct characters would always be all of it, therefore the answer is 1.
 Example 3:
 Input: s = "xxyz", k = 1
 Output: 4
 Explanation:
 The optimal way is to change s[0] or s[1] to something other than characters in s, for example, to change s[0] to w.
 Then s becomes "wxyz", which consists of 4 distinct characters, so as k is 1, it will divide into 4 partitions.
 Constraints:
 1 <= s.length <= 104
 s consists only of lowercase English letters.
 1 <= k <= 26
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPartitionsAfterOperations = function(s, k) {
    const n = s.length;
    let maxPartitions = 1;

    // Check the number of distinct characters in the original string
    const originalDistinct = new Set(s).size;

    // If the original string already has at most k distinct characters
    if (originalDistinct <= k) {
        return 1;
    }

    // Try changing each character to see if we can increase the number of partitions
    for (let i = 0; i < n; i++) {
        const originalChar = s[i];
        for (let j = 0; j < 26; j++) {
            const newChar = String.fromCharCode('a'.charCodeAt(0) + j);
            if (newChar !== originalChar) {
                const newString = s.slice(0, i) + newChar + s.slice(i + 1);
                const distinctCount = new Set(newString).size;
                if (distinctCount <= k) {
                    maxPartitions = Math.max(maxPartitions, 1);
                }
            }
        }
    }

    return maxPartitions;
};