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
int longestAwesome(char * s){
    int n = strlen(s);
    int maxLen = 0;
    int mask = 0;
    int dp[1024];
    memset(dp, -1, sizeof(dp));
    dp[0] = -1;
    for (int i = 0; i < n; i++) {
        mask ^= (1 << (s[i] - '0'));
        for (int j = 0; j< 10; j++) {
            int m = mask ^ (1 << j);
            if (dp[m] != -1) {
                maxLen = max(maxLen, i - dp[m]);
            }
        }
    }
    return maxLen;
}