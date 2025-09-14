/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
char * removeDuplicateLetters(char * s){
    int n = strlen(s);
    int i, j;
    int cnt[26] = {0};
    int vis[26] = {0};
    for (i = 0; i < n; i++) cnt[s[i] - 'a']++;
    char * ans = (char *) malloc(sizeof(char) * (n + 1));
    ans[n] = '\0';
    i = 0;
    for (j = 0; j < n;j++) {
        if (vis[s[j] - 'a']) continue;
        while (i > 0 && s[j] < ans[i - 1] && cnt[ans[i - 1] - 'a'] > 0) {
            vis[ans[i - 1] - 'a'] = 0;
            i--;
        }
        ans[i++] = s[j];
        vis[s[j] - 'a'] = 1;
    }
    return ans;
}