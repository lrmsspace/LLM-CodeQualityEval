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
class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int[] prefix = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (isVowel(s.charAt(i - 1)) ? 1 : 0);
        }
        int res = 0;
        for (int i = 0; i + k <= n; i++) {
            res = Math.max(res, prefix[i + k] - prefix[i]);
        }
        return res;        
    }
}