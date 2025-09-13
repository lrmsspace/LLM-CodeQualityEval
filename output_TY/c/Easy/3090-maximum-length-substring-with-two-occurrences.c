/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

int maximumLengthSubstring(char* s) {
    int i, j, k, l, n, m, cnt[26], ans;
    n = strlen(s);
    ans = 0;
    for (i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        m = 0;
        for (j = i; j < n; j++) {
            k = s[j] - 'a';
            if (cnt[k] == 2) {
                break;
            }
            cnt[k]++;
            m++;
        }
        ans = max(ans, m);
    }
    return ans;
    
}