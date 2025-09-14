/**https://leetcode.com/problems/longest-ideal-subsequence/ */
//You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
//	t is a subsequence of the string s.
//	The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
//Return the length of the longest ideal string.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
// 
//Example 1:
//Input: s = "acfgbd", k = 2
//Output: 4
//Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
//Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
//Example 2:
//Input: s = "abcd", k = 3
//Output: 4
//Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
// 
//Constraints:
//	1 <= s.length <= 105
//	0 <= k <= 25
//	s consists of lowercase English letters.
int longestIdealString(char * s, int k){
    int i, j, n, m, max, *dp, *p;
    n = strlen(s);
    dp = (int *)calloc(26, sizeof(int));
    p = (int *)calloc(26, sizeof(int));
    for (i = 0; i < n; i++) {
        j = s[i] - 'a';
        m = j - k;
        if (m < 0) m= 0;
    }
    for (i = 0; i < 26; i++) {
        p[i] = dp[i];
        dp[i] = 1;
    }
    max = 1;
    for (i = 1; i < n; i++) {
        j = s[i] - 'a';
        m = j - k;
        if (m < 0) m= 0;
        for (; m <= j + k && m < 26; m++) {
            if (m != j) {
                dp[j] = max(dp[j], p[m] + 1);
                max = max(max, dp[j]);
            }
        }
    }
    return max;
}