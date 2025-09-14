/**https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ */
//Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
//Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
// 
//Example 1:
//Input: s = "abciiidef", k = 3
//Output: 3
//Explanation: The substring "iii" contains 3 vowel letters.
//Example 2:
//Input: s = "aeiou", k = 2
//Output: 2
//Explanation: Any substring of length 2 contains 2 vowels.
//Example 3:
//Input: s = "leetcode", k = 3
//Output: 2
//Explanation: "lee", "eet" and "ode" contain 2 vowels.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
//	1 <= k <= s.length
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let count = 0;
    let maxCount = 0;
    
    for (let i = 0; i < s.length - k + 1; i++) {
        let substring = s.slice(i, i + k);
        let vowelCount = 0;
        
        for (let j = 0; j < substring.length; j++) {
            if (vowels.includes(substring[j])) {
                vowelCount++;
            }
        }
        
        if (vowelCount > maxCount) {
            maxCount = vowelCount;
        }
    }
    
    return maxCount;
    
};