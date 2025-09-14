/*
 You are given a string s, which is known to be a concatenation of anagrams of some string t.
 Return the minimum possible length of the string t.
 An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
 Example 1:
 Input: s = "abba"
 Output: 2
 Explanation:
 One possible string t could be "ba".
 Example 2:
 Input: s = "cdef"
 Output: 4
 Explanation:
 One possible string t could be "cdef", notice that t can be equal to s.
 Example 2:
 Input: s = "abcbcacabbaccba"
 Output: 3
 Constraints:
 1 <= s.length <= 105
 s consist only of lowercase English letters.
*/

int minAnagramLength(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    int minLen = len;
    int anagramCount = 0;
    
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            anagramCount++;
            count[i]--;
            if (anagramCount == len / 2) {
                minLen = min(minLen, i + 1);
                break;
            }
        }
    }
    
    return minLen;
    
}