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
    let dp = new Array(1 << n).fill(0).map(() => new Array(n).fill(0));
    let g = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i !== j) {
                let k = 0;
                while (words[i][k] === words[j][k]) ++k;
                g[i][j] = g[j][i] = k;
            }
        }
    }
    for (let mask = 0;mask < (1 << n); ++mask) {
        for (let i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                let mask2 = mask ^ (1 << i);
                for (let j = 0; j < n; ++j) {
                    if (mask2 & (1 << j)) {
                        dp[mask][i] = Math.max(dp[mask][i], dp[mask2][j] + g[j][i]);
                    }
                }
            }
        }
    }
    let mask = (1 << n) - 1;
    let i = -1, j = -1;
    for (let k = 0; k < n; ++k) {
        if (dp[mask][k] > dp[mask][i]) {
            i = k;
            j = mask;
        }
    }
    let ans = words[i];
    while (j > 0) {
        let k = -1;
        for (let l = 0; l < n; ++l) {
            if (j & (1 << l)) {
                if (l === i) continue;
                if (k === -1 || dp[j][l] +g[l][i] > dp[j][k] + g[k][i])
                    k = l;
            }
        }
    }
    while (j !== (1 << i) - 1) {
        ans = words[k] + ans.slice(g[k][i]);
        let tmp = j;
        j ^= 1 << k;
        k = -1;
        for (let l = 0; l < n; ++l) {
            if (tmp & (1 << l)) {
                if (l === k) continue;
                if (k === -1 || dp[tmp][l] + g[l][k] > dp[tmp][k] + g[k][i])
                    k = l;
            }
        }
    }
    return ans;

};