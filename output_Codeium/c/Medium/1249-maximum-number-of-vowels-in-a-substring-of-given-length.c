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
int maxVowels(char* s, int k) {
    
    int count = 0, max = 0, i = 0, j = 0;
    while (j < strlen(s)) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
            count++;
        }
        if (j - i + 1 > k) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count--;
            }
            i++;
        }
        max = fmax(max, count);
        j++;
    }
    return max;
}
