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
    int i, j, k, l, n, m, cnt[26] = {0}, ans = INT_MAX;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (j = i, k = 0; j < n; j++) {
            cnt[s[j] - 'a']++;
            k++;
            m = 0;
            for (l = 0; l < 26; l++) {
                if (cnt[l] != 0) {
                    m++;
                }
            }
            if (m == 26) {
                ans = min(ans, k);
                break;
            }
        }
    }
    return ans;
    
}