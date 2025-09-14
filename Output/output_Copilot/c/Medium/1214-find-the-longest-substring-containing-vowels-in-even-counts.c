/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.
int findTheLongestSubstring(char* s) {
    int n = strlen(s);
    int* pos = (int*)malloc(sizeof(int) * (1 << 5));
    memset(pos, -1, sizeof(int) * (1 << 5));
    pos[0] = 0;
    int state = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') state ^= 1 << 0;
        if (s[i] == 'e') state ^= 1 << 1;
        if (s[i] == 'i') state ^= 1 << 2;
        if (s[i] == 'o') state ^= 1 << 3;
        if (s[i] == 'u') state ^= 1 << 4;
        if (~pos[state]) ans = fmax(ans, i + 1 - pos[state]);
        else pos[state] = i + 1;
    }
    free(pos);
    return ans;    
}