/**https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/ */
//You are given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.
//	For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.
//Return the minimum cost to change the final value of the expression.
//	For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.
//The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:
//	Turn a '1' into a '0'.
//	Turn a '0' into a '1'.
//	Turn a '&' into a '|'.
//	Turn a '|' into a '&'.
//Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.
// 
//Example 1:
//Input: expression = "1&(0|1)"
//Output: 1
//Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
//The new expression evaluates to 0. 
//Example 2:
//Input: expression = "(0&0)&(0&0&0)"
//Output: 3
//Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
//The new expression evaluates to 1.
//Example 3:
//Input: expression = "(0|(1|0&1))"
//Output: 1
//Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
//The new expression evaluates to 0.
// 
//Constraints:
//	1 <= expression.length <= 105
//	expression only contains '1','0','&','|','(', and ')'
//	All parentheses are properly matched.
//	There will be no empty parentheses (i.e: "()" is not a substring of expression).
int minOperationsToFlip(char* expression) {
    int len = strlen(expression);
    int n = len / 2 + 1;
    int dp[n][2][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (expression[i * 2] == '0') {
            dp[i][0][0] = 0;
            dp[i][1][1] = 1;
        } else {
            dp[i][0][1] = 1;
            dp[i][1][0] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (expression[i * 2 + 1] == '&') {
            dp[i][0][0] = fmin(dp[i][0][0], dp[i][0][0] + dp[i + 1][0][0]);
            dp[i][0][1] = fmin(dp[i][0][1], dp[i][0][0] + dp[i + 1][0][1]);
            dp[i][1][0] = fmin(dp[i][1][0], dp[i][1][1] + dp[i + 1][1][0]);
            dp[i][1][1] = fmin(dp[i][1][1], dp[i][1][1] + dp[i + 1][1][1]);
        } else if (expression[i * 2 + 1] == '|') {
            dp[i][0][0] = fmin(dp[i][0][0], dp[i][0][0] + dp[i + 1][0][0]);
            dp[i][0][1] = fmin(dp[i][0][1], dp[i][0][1] + dp[i + 1][0][1]);
            dp[i][1][0] = fmin(dp[i][1][0], dp[i][1][0] + dp[i + 1][1][0]);
            dp[i][1][1] = fmin(dp[i][1][1], dp[i][1][1] + dp[i + 1][1][1]);
        }
            
}