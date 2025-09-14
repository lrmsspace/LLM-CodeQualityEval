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
var shortestSuperstring = function(words) 
{
    const n = words.length;
    const overlaps = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            for (let k = Math.min(words[i].length, words[j].length); k > 0; k--) {
                if (words[i].endsWith(words[j].substring(0, k))) {
                    overlaps[i][j] = k;
                    break;
                }
            }
        }
    }
    const dp = Array.from({ length: 1 << n }, () => Array(n).fill(0));
    const parent = Array.from({ length: 1 << n }, () => Array(n).fill(-1));
    for (let mask = 0; mask < 1 << n; mask++) {
        for (let bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit)) === 0) continue;
            const prevMask = mask ^ (1 << bit);
            if (prevMask === 0) continue;
            for (let i = 0; i < n; i++) {
                if ((prevMask & (1 << i)) === 0) continue;
                const val = dp[prevMask][i] + overlaps[i][bit];
                if (val > dp[mask][bit]) {
                    dp[mask][bit] = val;
                    parent[mask][bit] = i;
                }
            }
        }
    }
    const perm = [];
    let mask = (1 << n) - 1;
    let look = dp[mask].indexOf(Math.max(...dp[mask]));
    while (look !== -1) {
        perm.push(look);
        const temp = mask;
        mask ^= 1 << look;
        look = parent[temp][look];
    }
    perm.reverse();
    let ans = words[perm[0]];
    for (let i = 1; i < n; i++) {
        const overlap = overlaps[perm[i - 1]][perm[i]];
        ans += words[perm[i]].substring(overlap);
    }
    return ans;
};