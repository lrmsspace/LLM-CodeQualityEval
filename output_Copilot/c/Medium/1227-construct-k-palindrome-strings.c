/**https://leetcode.com/problems/construct-k-palindrome-strings/ */
//Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
// 
//Example 1:
//Input: s = "annabelle", k = 2
//Output: true
//Explanation: You can construct two palindromes using all characters in s.
//Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
//Example 2:
//Input: s = "leetcode", k = 3
//Output: false
//Explanation: It is impossible to construct 3 palindromes using all the characters of s.
//Example 3:
//Input: s = "true", k = 4
//Output: true
//Explanation: The only possible solution is to put each character in a separate string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
//	1 <= k <= 105
bool canConstruct(char* s, int k) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    int e[26] = {0};
    int f[26] = {0};
    int g[26] = {0};
    int h[26] = {0};
    int ans = 0;
    for(i = 0; i < strlen(s); i++) {
        a[s[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {
        if(a[i] % 2 == 1) {
            ans++;
        }
    }
    if(ans > k) {
        return false;
    }
    return true;
        
}