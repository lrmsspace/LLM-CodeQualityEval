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
    let nums = [];
    for (let i = 0; i < n; i++) {
        nums.push(s.charCodeAt(i) - 'a'.charCodeAt(0));
    }
    let a = 26;
    let mod = 2**32;
    let left = 1, right = n;
    let power = 1;
    for (let i = 0; i < left; i++) {
        power = (power * a) % mod;
    }
    let seen = new Set();
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let start = 0;
        let found = false;
        let curr = 0;
        for (let i = 0; i < mid; i++) {
            curr = (curr * a + nums[i]) % mod;
        }
        seen.clear();
        seen.add(curr);
        for (let i = mid; i < n; i++) {
            curr = (curr * a + nums[i] - nums[i - mid] * power % mod + mod) % mod;
            if (seen.has(curr)) {
                start = i - mid + 1;
                found = true;
                break;
            }
            seen.add(curr);
        }
        if (found) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    let start = left - 1;
    if (start === 0) return "";
    return s.substring(start, start + left - 1);
};