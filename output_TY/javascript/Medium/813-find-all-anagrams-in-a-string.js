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
    let ans = [];
    let map = new Map();
    for(let i = 0; i < p.length; i++){
        if(map.has(p[i])){
            map.set(p[i], map.get(p[i]) + 1);
        }else{
            map.set(p[i], 1);
        }
    }
    let left = 0;
    let right = 0;
    let count = map.size;
    while(right < s.length){
        let c = s[right];
        if(map.has(c)){
            map.set(c, map.get(c) - 1);
            if(map.get(c) === 0){
                count--;
            }
        }
    }
    while(right < s.length){
        if(count === 0){
            ans.push(left);
        }
        let c = s[right];
        if(map.has(c)){
            map.set(c, map.get(c) - 1);
            if(map.get(c) === 0){
                count--;
            }
        }
        right++;
        c = s[left];
        if(map.has(c)){
            map.set(c, map.get(c) + 1);
            if(map.get(c) > 0){
                count++;
            }
        }
        left++;
   }
   return ans;
};