/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestDupSubstring = function(s) {
    let n = s.length;
    let l = 1;
    let r = n - 1;
    let ans = "";
    let mod = 2 ** 63 - 1;
    let base = 26;

    while (l <= r) {
        let mid = Math.floor((l + r) / 2);
        let seen = new Set();
        let hash = 0;
        let basePow = 1;

        for (let i = 0; i < mid; i++) {
            hash = (hash * base + s.charCodeAt(i) - 'a'.charCodeAt(0)) % mod;
            basePow = (basePow * base) % mod;
        }
        seen.add(hash);

        let foundDup = false;

        for (let i = mid; i < n; i++) {
            hash = (hash * base - (s.charCodeAt(i - mid) - 'a'.charCodeAt(0)) * basePow + (s.charCodeAt(i) - 'a'.charCodeAt(0))) % mod;
            if (hash < 0) hash += mod;

            if (seen.has(hash)) {
                foundDup = true;
                ans = s.substring(i - mid + 1, i + 1);
                break;
            }
            seen.add(hash);
        }

        if (foundDup) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;    
};