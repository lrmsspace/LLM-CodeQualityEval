/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    const charCount = {};
    for (const char of s) {
        charCount[char] = (charCount[char] || 0) + 1;
    }
    const maxHeap = [];
    for (const char in charCount) {
        maxHeap.push([-charCount[char], char]);
    }
    maxHeap.sort((a, b) => a[0] - b[0]);
    const result = [];
    while (maxHeap.length > 1) {
        const [count1, char1] = maxHeap.pop();
        const [count2, char2] = maxHeap.pop();
        result.push(char1, char2);
        if (count1 < -1) {
            maxHeap.push([count1 + 1, char1]);
        }
        if (count2 < -1) {
            maxHeap.push([count2 + 1, char2]);
        }
        maxHeap.sort((a, b) => a[0] - b[0]);
    }
    if (maxHeap.length) {
        if (maxHeap[0][0] < -1) {
            return "";
        }
        result.push(maxHeap[0][1]);
    }
    return result.join("");
};