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
    int n = strlen(s);
    int dp[n][10] = {0};
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cnt[10] = {0};
        for (int j = i; j < n; j++) {
            cnt[s[j] - '0']++;
            int cur = 0;
            for (int k = 0; k < 10; k++) {
                cur += cnt[k] % 2;
            }
            dp[i][cur]++;
            res = fmax(res, dp[i][cur]);
        }
    }
    return res;
}