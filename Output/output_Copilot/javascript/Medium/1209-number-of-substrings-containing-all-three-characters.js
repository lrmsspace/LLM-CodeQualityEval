/**https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ */
//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// 
//Example 1:
//Input: s = "abcabc"
//Output: 10
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
//Example 2:
//Input: s = "aaacb"
//Output: 3
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
//Example 3:
//Input: s = "abc"
//Output: 1
// 
//Constraints:
//	3 <= s.length <= 5 x 10^4
//	s only consists of a, b or c characters.
/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    let count = 0;
    let left = 0;
    let right = 0;
    const map = { a: 0, b: 0, c: 0 };
    
    while (right < s.length) {
        map[s[right]]++;
        
        while (map.a > 0 && map.b > 0 && map.c > 0) {
            count += s.length - right;
            map[s[left]]--;
            left++;
        }
        
        right++;
    }
    
    return count;    
};