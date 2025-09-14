/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
//Example 1:
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//Constraints:
//	1 <= s.length, p.length <= 3 * 104
//	s and p consist of lowercase English letters.
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    const lenS = s.length;
    const lenP = p.length;
    if (lenS < lenP) return [];
    
    const mapP = new Map();
    for (let i = 0; i < lenP; i++) {
        mapP.set(p[i], (mapP.get(p[i]) || 0) + 1);
    }
    
    let left = 0;
    let right = 0;
    const result = [];
    const mapS = new Map();
    
    while (right < lenS) {
        mapS.set(s[right], (mapS.get(s[right]) || 0) + 1);
        
        if (right - left + 1 === lenP) {
            if (mapS.equals(mapP)) {
                result.push(left);
            }
            mapS.set(s[left], mapS.get(s[left]) - 1);
            if (mapS.get(s[left]) === 0) {
                mapS.delete(s[left]);
            }
            left++;
        }
        
        right++;
    }
    
    return result;
    
};