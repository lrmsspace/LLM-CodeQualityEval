/**https://leetcode.com/problems/find-the-substring-with-maximum-cost/ */
//You are given a string s, a string chars of distinct characters and an integer array vals of the same length as chars.
//The cost of the substring is the sum of the values of each character in the substring. The cost of an empty string is considered 0.
//The value of the character is defined in the following way:
//	If the character is not in the string chars, then its value is its corresponding position (1-indexed) in the alphabet.
//	
//		For example, the value of 'a' is 1, the value of 'b' is 2, and so on. The value of 'z' is 26.
//	
//	
//	Otherwise, assuming i is the index where the character occurs in the string chars, then its value is vals[i].
//Return the maximum cost among all substrings of the string s.
// 
//Example 1:
//Input: s = "adaa", chars = "d", vals = [-1000]
//Output: 2
//Explanation: The value of the characters "a" and "d" is 1 and -1000 respectively.
//The substring with the maximum cost is "aa" and its cost is 1 + 1 = 2.
//It can be proven that 2 is the maximum cost.
//Example 2:
//Input: s = "abc", chars = "abc", vals = [-1,-1,-1]
//Output: 0
//Explanation: The value of the characters "a", "b" and "c" is -1, -1, and -1 respectively.
//The substring with the maximum cost is the empty substring "" and its cost is 0.
//It can be proven that 0 is the maximum cost.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consist of lowercase English letters.
//	1 <= chars.length <= 26
//	chars consist of distinct lowercase English letters.
//	vals.length == chars.length
//	-1000 <= vals[i] <= 1000
int maximumCostSubstring(char* s, char* chars, int* vals, int valsSize) {
    int n = strlen(s);
    int m = strlen(chars);
    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));
    int result = 0;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + s[i - 1] - 'a' + 1;
        for (int j = 0; j < m; j++) {
            if (s[i - 1] == chars[j]) {
                dp[0][i] = fmax(dp[0][i], dp[1][j] + vals[j]);
            }
        }
        result = fmax(result, dp[0][i]);
        for (int j = 0; j < m; j++) {
            dp[1][j] = fmax(dp[1][j], dp[0][i]);
        }
    }
    return result;    
}