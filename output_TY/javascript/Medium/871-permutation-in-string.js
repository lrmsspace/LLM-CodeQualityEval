/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let s1Map = new Map();
    for(let i=0;i<s1.length;i++){
        s1Map.set(s1[i],s1Map.has(s1[i])?s1Map.get(s1[i])+1:1);
    }
    let start = 0;
    let end = 0;
    let count = s1Map.size;
    let s2Map = new Map();
    while(end<s2.length){
        let c = s2[end];
        s2Map.set(c,s2Map.has(c)?s2Map.get(c)+1:1);
        if(s1Map.has(c) && s1Map.get(c)===s2Map.get(c))
            count--;
    }
    while(end<s2.length){
        if(count===0)
            return true;
        end++;
        if(end-start>=s1.length){
            let c = s2[start];
            if(s1Map.has(c) && s1Map.get(c)===s2Map.get(c))
                count++;
            s2Map.set(c,s2Map.get(c)-1);
            if(s2Map.get(c)===0)
                s2Map.delete(c);
        }
        start++;
    }
    return false;
};