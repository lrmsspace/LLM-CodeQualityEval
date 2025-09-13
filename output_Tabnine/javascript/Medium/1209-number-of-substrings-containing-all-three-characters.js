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
    let n = s.length;
    let count = [0, 0, 0];
    let ans = 0;
    
    for (let i = 0, j = 0; i < n; i++) {
        count[s.charCodeAt(i) - 97]++;
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            ans += n - j + 1;
            count[s.charCodeAt(j) - 97]--;
            j++;
        }
    }
    
    return ans;
    
};