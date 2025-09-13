/*
 You are given an array of strings words. Find all shortest common supersequences (SCS) of words that are not permutations of each other.
 A shortest common supersequence is a string of minimum length that contains each string in words as a subsequence.
 Return a 2D array of integers freqs that represent all the SCSs. Each freqs[i] is an array of size 26, representing the frequency of each letter in the lowercase English alphabet for a single SCS. You may return the frequency arrays in any order.
 Example 1:
 Input: words = ["ab","ba"]
 Output: [[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aba" and "bab". The output is the letter frequencies for each one.
 Example 2:
 Input: words = ["aa","ac"]
 Output: [[2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aac" and "aca". Since they are permutations of each other, keep only "aac".
 Example 3:
 Input: words = ["aa","bb","cc"]
 Output: [[2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 "aabbcc" and all its permutations are SCSs.
 Constraints:
 1 <= words.length <= 256
 words[i].length == 2
 All strings in words will altogether be composed of no more than 16 unique lowercase letters.
 All strings in words are unique.
*/

/**
 * @param {string[]} words
 * @return {number[][]}
 */
var supersequences = function(words) {
    const n = words.length;
    const m = words[0].length;
    const dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const freqs = new Array(n).fill(0).map(() => new Array(26).fill(0));
    
    const countFreq = (str) => {
        const freq = new Array(26).fill(0);
        for (let i = 0; i < str.length; i++) {
            freq[str.charCodeAt(i) - 97]++;
        }
        return freq;
    };
    
    for (let i = 0; i < n; i++) {
        freqs[i] = countFreq(words[i]);
    }
    
    const findSCS = (i, j) => {
        if (i === j) {
            return words[i];
        }
        if (dp[i][j] !== 0) {
            return dp[i][j];
        }
        const s1 = words[i];
        const s2 = words[j];
        let k = 0;
        while (k < s1.length && k < s2.length && s1[k] === s2[k]) {
            k++;
        }
        if (k === s1.length) {
            dp[i][j] = s2;
            return s2;
        }
        if (k === s2.length) {
            dp[i][j] = s1;
            return s1;
        }
        const c1 = findSCS(i, j - 1);
        const c2 = findSCS(i + 1, j);
        let res = c1.length <= c2.length ? c1 : c2;
        for (let l = 1; l <= c1.length; l++) {
            const sub = c1.substring(c1.length - l);
            if (c2.indexOf(sub) !== -1) {
                res = c1 + c2.substring(c2.indexOf(sub) + l);
                break;
            }
        }
        dp[i][j] = res;
        return res;
    };
    
    const res = findSCS(0, n - 1);
    for (let i = 0; i < res.length; i++) {
        freqs[n - 1][res.charCodeAt(i) - 97]++;
    }
    
    return freqs.slice(n - 1);        
};