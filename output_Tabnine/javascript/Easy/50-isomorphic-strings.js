/**https://leetcode.com/problems/isomorphic-strings/ */
//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// 
//Example 1:
//Input: s = "egg", t = "add"
//Output: true
//Explanation:
//The strings s and t can be made identical by:
//	Mapping 'e' to 'a'.
//	Mapping 'g' to 'd'.
//Example 2:
//Input: s = "foo", t = "bar"
//Output: false
//Explanation:
//The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
//Example 3:
//Input: s = "paper", t = "title"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	t.length == s.length
//	s and t consist of any valid ascii character.
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    // Create two empty objects to store mappings
    const mapS = {};
    const mapT = {};
    
    // Iterate through the strings
    for (let i = 0; i < s.length; i++) {
        // If characters in s and t are already mapped, check if they match
        if (mapS[s[i]] && mapS[s[i]]!== t[i]) {
            return false;
        }
        if (mapT[t[i]] && mapT[t[i]]!== s[i]) {
            return false;
        }
        
        // Otherwise, map characters in s and t
        mapS[s[i]] = t[i];
        mapT[t[i]] = s[i];
    }
    
    // If all characters are mapped successfully, return true
    return true;
    
};