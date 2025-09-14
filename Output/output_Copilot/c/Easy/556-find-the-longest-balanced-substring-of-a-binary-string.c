/**https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/ */
//You are given a binary string s consisting only of zeroes and ones.
//A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.
//Return the length of the longest balanced substring of s.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "01000111"
//Output: 6
//Explanation: The longest balanced substring is "000111", which has length 6.
//Example 2:
//Input: s = "00111"
//Output: 4
//Explanation: The longest balanced substring is "0011", which has length 4. 
//Example 3:
//Input: s = "111"
//Output: 0
//Explanation: There is no balanced substring except the empty substring, so the answer is 0.
// 
//Constraints:
//	1 <= s.length <= 50
//	'0' <= s[i] <= '1'
int findTheLongestBalancedSubstring(char* s) {
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * len);
    int *stack = (int *)malloc(sizeof(int) * len);
    int top = -1;
    int max = 0;
    for (int i = 0; i < len; i++) {
        dp[i] = 0;
        if (s[i] == '1') {
            if (top != -1) {
                dp[i] = i - stack[top] + 1;
                if (top > 0) {
                    dp[i] += dp[stack[top - 1] - 1];
                }
                if (dp[i] > max) {
                    max = dp[i];
                }
                top--;
            }
        } else {
            stack[++top] = i;
        }
    }
    return max;    
}