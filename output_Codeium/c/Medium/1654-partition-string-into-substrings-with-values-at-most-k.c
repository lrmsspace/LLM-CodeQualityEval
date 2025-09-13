/**https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/ */
//You are given a string s consisting of digits from 1 to 9 and an integer k.
//A partition of a string s is called good if:
//	Each digit of s is part of exactly one substring.
//	The value of each substring is less than or equal to k.
//Return the minimum number of substrings in a good partition of s. If no good partition of s exists, return -1.
//Note that:
//	The value of a string is its result when interpreted as an integer. For example, the value of "123" is 123 and the value of "1" is 1.
//	A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "165462", k = 60
//Output: 4
//Explanation: We can partition the string into substrings "16", "54", "6", and "2". Each substring has a value less than or equal to k = 60.
//It can be shown that we cannot partition the string into less than 4 substrings.
//Example 2:
//Input: s = "238182", k = 5
//Output: -1
//Explanation: There is no good partition for this string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is a digit from '1' to '9'.
//	1 <= k <= 109
// 
//.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
//}
//.spoiler {overflow:hidden;}
//.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
//.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
//.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
int minimumPartition(char* s, int k) {
    int n = strlen(s);
    int dp[n + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = i; j >= 1; --j) {
            cur = cur * 10 + s[j - 1] - '0';
            if (cur <= k) {
                dp[i] = fmin(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] == 0x3f3f3f3f ? -1 : dp[n];
}