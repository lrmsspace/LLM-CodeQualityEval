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
    const charCount = new Map();
    for (const char of s) {
        charCount.set(char, (charCount.get(char) || 0) + 1);
    }

    const maxHeap = [];
    for (const [char, count] of charCount.entries()) {
        maxHeap.push([-count, char]);
    }
    maxHeap.sort();

    let result = '';
    while (maxHeap.length > 0) {
        const [count1, char1] = maxHeap.shift();
        result += char1;

        if (maxHeap.length > 0) {
            const [count2, char2] = maxHeap.shift();
            result += char2;

            if (count2 + 1 < 0) {
                maxHeap.push([count2 + 1, char2]);
            }
        }

        if (count1 + 1 < 0) {
            maxHeap.push([count1 + 1, char1]);
        }
        
        maxHeap.sort();
    }

    return result.length === s.length ? result : '';    
};