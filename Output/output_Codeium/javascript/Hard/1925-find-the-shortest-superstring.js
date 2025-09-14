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
    let dp = Array.from({length: 1 << words.length}, () => Array(words.length).fill(0));
    for (let i = 0; i < words.length; i++) dp[1 << i][i] = words[i].length;

    for (let mask = 1; mask < (1 << words.length); mask++) {
        if (dp[mask].some(v => v === 0)) continue;
        for (let i = 0; i < words.length; i++) {
            if (~mask & (1 << i)) continue;
            let nextMask = mask | (1 << i);
            for (let j = 0; j < words.length; j++) {
                if (i === j || ~(mask) & (1 << j)) continue;
                dp[nextMask][i] = Math.max(dp[nextMask][i], dp[mask][j] + words[i].length - overlap(words[j], words[i]));
            }
        }
    }

    let res = [];
    let mask = (1 << words.length) - 1;
    for (let i = 0; i < words.length; i++) {
        if (dp[mask][i] === 0) continue;
        res.push(words[i]);
        for (let j = 0; j < words.length; j++) {
            if (i === j || ~(mask) & (1 << j)) continue;
            if (dp[mask][i] === dp[mask ^ (1 << i)][j] + words[i].length - overlap(words[j], words[i])) {
                mask ^= (1 << i);
                break;
            }
        }
    }

    return res.join('');

    function overlap(s1, s2) {
        for (let i = Math.min(s1.length, s2.length); i > 0; i--) {
            if (s1.slice(-i) === s2.slice(0, i)) return i;
        }
        return 0;
    }
};