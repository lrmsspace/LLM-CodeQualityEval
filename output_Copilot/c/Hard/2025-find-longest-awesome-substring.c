/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.
// 
//Example 1:
//Input: s = "3242415"
//Output: 5
//Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
//Example 2:
//Input: s = "12345678"
//Output: 1
//Example 3:
//Input: s = "213123"
//Output: 6
//Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of digits.
int longestAwesome(char* s) {
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * (1 << 10));
    memset(dp, -1, sizeof(int) * (1 << 10));
    dp[0] = 0;
    int mask = 0;
    int res = 0;
    for (int i = 1; i <= len; i++) {
        mask ^= 1 << (s[i - 1] - '0');
        if (dp[mask] != -1) {
            res = fmax(res, i - dp[mask]);
        } else {
            dp[mask] = i;
        }
        for (int j = 0; j < 10; j++) {
            int tmp = mask ^ (1 << j);
            if (dp[tmp] != -1) {
                res = fmax(res, i - dp[tmp]);
            }
        }
    }
    free(dp);
    return res;    
}