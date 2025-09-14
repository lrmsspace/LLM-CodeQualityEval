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
    const n = words.length;
    const dp = Array.from({ length: 1 << n }, () => Array(n).fill(Infinity));
    const path = Array.from({ length: 1 << n }, () => Array(n).fill(-1));
    const overlap = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        dp[1 << i][i] = words[i].length;
        for (let j = 0; j < n; j++) {
            if (i !== j) {
                let k = 0;
                while (k < words[i].length && k < words[j].length && words[i][k] === words[j][k]) {
                    k++;
                }
                overlap[i][j] = k;
            }
        }
    }

    for (let mask = 1; mask < (1 << n); mask++) {
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) === 0) continue;
            for (let j = 0; j < n; j++) {
                if ((mask & (1 << j)) !== 0) continue;
                const newMask = mask | (1 << j);
                const newLength = dp[mask][i] + words[j].length - overlap[i][j];
                if (newLength < dp[newMask][j]) {
                    dp[newMask][j] = newLength;
                    path[newMask][j] = i;
                }
            }
        }
    }

    let minLength = Infinity;
    let lastIndex = -1;
    for (let i = 0; i < n; i++) {
        if (dp[(1 << n) - 1][i] < minLength) {
            minLength = dp[(1 << n) - 1][i];
            lastIndex = i;
        }
    }

    let mask = (1 << n) - 1;
    const result = [];
    while (lastIndex !== -1) {
        result.push(words[lastIndex]);
        const prevIndex = path[mask][lastIndex];
        mask ^= (1 << lastIndex);
        lastIndex = prevIndex;
    }

    result.reverse();
    let superstring = result[0];
    for (let i = 1; i < result.length; i++) {
        const prev = result[i - 1];
        const curr = result[i];
        const overlapLength = overlap[words.indexOf(prev)][words.indexOf(curr)];
        superstring += curr.slice(overlapLength);
    }
    return superstring;    
};