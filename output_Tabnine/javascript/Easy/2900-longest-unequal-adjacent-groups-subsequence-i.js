/*
 You are given a string array words and a binary array groups both of length n.
 A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).
 Your task is to select the longest alternating subsequence from words.
 Return the selected subsequence. If there are multiple answers, return any of them.
 Note: The elements in words are distinct.
 Example 1:
 Input: words = ["e","a","b"], groups = [0,0,1]
 Output: ["e","b"]
 Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.
 Example 2:
 Input: words = ["a","b","c","d"], groups = [1,0,1,1]
 Output: ["a","b","c"]
 Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.
 Constraints:
 1 <= n == words.length == groups.length <= 100
 1 <= words[i].length <= 10
 groups[i] is either 0 or 1.
 words consists of distinct strings.
 words[i] consists of lowercase English letters.
*/

/**
 * @param {string[]} words
 * @param {number[]} groups
 * @return {string[]}
 */
var getLongestSubsequence = function(words, groups) {
    const n = words.length;
    const dp = Array(n).fill(0).map(() => Array(n).fill(false));
    let maxLength = 0;
    let endIndex = -1;
    
    for (let i = 0; i < n; i++) {
        for (let j = i - 1; j >= 0; j--) {
            if (groups[i]!== groups[j] && words[i] > words[j]) {
                dp[j][i] = dp[j + 1][i - 1] || dp[j][i - 1];
                if (dp[j][i]) {
                    if (maxLength < i - j + 1) {
                        maxLength = i - j + 1;
                        endIndex = i;
                    }
                }
            }
        }
    }
    return words.slice(endIndex - maxLength + 1, endIndex + 1);
    
};