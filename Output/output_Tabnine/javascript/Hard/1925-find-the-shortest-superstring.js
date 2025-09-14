/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
/**
 * @param {string[]} words
 * @return {string}
 */
var shortestSuperstring = function(words) {
    let n = words.length;
    let dp = Array(1 << n).fill(Infinity);
    let parent = Array(1 << n).fill(-1);
    let prefixSum = Array(n).fill(0);
    
    // Calculate prefix sum for each word
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            prefixSum[i] ^= prefixSum[j] ^= prefixSum[i] ^= words[j].indexOf(words[i]);
        }
    }
    
    // Build the DP table
    for (let mask = 1; mask < (1 << n); mask++) {
        for (let i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                let prevMask = mask ^ (1 << i);
                let prevCost = dp[prevMask];
                if (prevCost < Infinity) {
                    let newCost = prevCost + prefixSum[i];
                    if (newCost < dp[mask]) {
                        dp[mask] = newCost;
                        parent[mask] = prevMask;
                    }
                }
            }
        }
    }
    
    // Reconstruct the shortest superstring
    let result = '';
    let currentMask = (1 << n) - 1;
    while (currentMask > 0) {
        result = words[0] + result;
        let prevMask = parent[currentMask];
        for (let i = 0; i < n; i++) {
            if ((currentMask >> i) & 1 && (prevMask >> i) & 1) {
                result = words[i] + result;
                break;
            }
        }
        currentMask = prevMask;
    }
    
    return result;
    

};