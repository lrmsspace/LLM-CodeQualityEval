/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var kSimilarity = function(s1, s2) {
    if (s1 === s2) return 0;
    const n = s1.length;
    const queue = [[s1, 0]];
    const visited = new Set([s1]);
    while (queue.length) {
        const [s, k] = queue.shift();
        if (s === s2) return k;
        let i = 0;
        while (s[i] === s2[i]) i++;
        for (let j = i + 1; j < n; j++) {
            if (s[j] === s2[j]) continue;
            if (s[j] === s2[i]) {
                const newS = s.slice(0, i) + s[j] + s.slice(i + 1, j) + s[i] + s.slice(j + 1);
                if (!visited.has(newS)) {
                    visited.add(newS);
                    queue.push([newS, k + 1]);
                }
            }
        }
    }
    return -1;
};